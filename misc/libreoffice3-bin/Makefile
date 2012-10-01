# $NetBSD: Makefile,v 1.14 2012/10/01 13:27:01 ryoon Exp $

DISTNAME=		libreoffice3-bin	# overridden below
PKGNAME=		libreoffice3-bin-${OO_RELEASE}
CATEGORIES=		misc
MASTER_SITES=		http://download.documentfoundation.org/libreoffice/stable/${OO_RELEASE}/rpm/x86/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		http://www.libreoffice.org/
COMMENT=		Integrated office productivity suite (binary pkg)
LICENSE=		gnu-lgpl-v3

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice-bin-[0-9]*
CONFLICTS+=		openoffice2-bin-[0-9]*
CONFLICTS+=		openoffice2-[0-9]*
CONFLICTS+=		openoffice3-[0-9]*
CONFLICTS+=		openoffice3-bin-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*

OO_VER=			3
OO_BASEVER=		3.6
OO_RELEASE=		3.6.1
PLIST_SUBST+=		VER=${OO_VER:Q} BASEVER=${OO_BASEVER:Q}
MESSAGE_SUBST+=		VER=${OO_VER:Q}
FILES_SUBST+=		VER=${OO_VER:Q}

TEMP?=			${WRKSRC}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
BUILD_DIRS=		# empty

PLIST_SRC=		${PKGDIR}/PLIST.proglinks
PLIST_SRC+=		${WRKDIR}/PLIST
PLIST_SRC+=		${PKGDIR}/PLIST.dirs

EMUL_PLATFORMS=		linux-i386
#EMUL_PLATFORMS+=	solaris-i386 solaris-sparc
EMUL_MODULES.linux=	freetype2 x11 locale png fontconfig
EMUL_REQD=		suse>=11.3

EMUL_PKG_FMT=		rpm
RPMFILES=		${WRKSRC}/RPMS/*.rpm
RPM2PKG_PREFIX=		${DESTDIR}${PREFIX}
RPM2PKG_SUBPREFIX=	# empty
RPM2PKG_STAGE=		do-install
RUN_LDCONFIG=		no

USE_TOOLS+=	patch

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
DISTNAME=		LibO_${OO_RELEASE}_Linux_x86_install-rpm_en-US
WRKSRC=			${WRKDIR}/LibO_${OO_RELEASE}.2_Linux_x86_install-rpm_en-US
.elif ${EMUL_PLATFORM} == "solaris-i386"
DISTNAME=		OOo_${OO_RELEASE}_Solaris_x86_install_en-US
WRKSRC=			${WRKDIR}/OOO320_m18_native_packed-1_en-US.9502/packages
.elif ${EMUL_PLATFORM} == "solaris-sparc"
DISTNAME=		OOo_${OO_RELEASE}_Solaris_Sparc_install_en-US
WRKSRC=			${WRKDIR}/OOO320_m18_native_packed-1_en-US.9502/packages
.endif

.include "options.mk"

INSTALLATION_DIRS= bin

do-install:
#	${PATCH} -d ${DESTDIR}${PREFIX}/opt/libreoffice${OO_BASEVER}/program < ${FILESDIR}/soffice-patch
#	${RM} -f ${DESTDIR}${PREFIX}/opt/libreoffice${OO_BASEVER}/program/soffice.orig
	${PATCH} -d ${DESTDIR}${PREFIX}/opt/libreoffice${OO_BASEVER}/program < ${FILESDIR}/spadmin-patch
	${RM} -f ${DESTDIR}${PREFIX}/opt/libreoffice${OO_BASEVER}/program/spadmin.orig
	uniq ${RPM2PKG_PLIST} | \
		${SED} -e 's,^@exec mkdir -m 755 -p %D/,@pkgdir,' > ${WRKDIR}/PLIST
	${RM} -f ${DESTDIR}${PREFIX}/bin/soffice
	${SED}  -e "s|@@PREFIX@@|${PREFIX}|g" -e "s|@@OO_VER@@|${OO_VER}|g" \
		-e "s|@@JAVA_HOME@@|${PKG_JAVA_HOME}|g" \
		-e "s|@@OO_BASEVER@@|${OO_BASEVER}|g" \
		< ${FILESDIR}/soffice > ${DESTDIR}${PREFIX}/bin/soffice
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/soffice
.for i in scalc sdraw simpress smath spadmin swriter
	${LN} -sf ../opt/libreoffice${OO_BASEVER}/program/${i} ${DESTDIR}${PREFIX}/bin/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
