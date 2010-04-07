# $NetBSD: Makefile,v 1.6 2010/04/07 18:04:46 joerg Exp $

DISTNAME=		openoffice3-bin	# overridden below
PKGNAME=		openoffice3-bin-${OO_RELEASE}
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_OPENOFFICE:=stable/${OO_RELEASE}/}

MAINTAINER=		bad@NetBSD.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (binary pkg)

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice-bin-[0-9]*
CONFLICTS+=		openoffice2-bin-[0-9]*
CONFLICTS+=		openoffice2-[0-9]*
CONFLICTS+=		openoffice3-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*

OO_VER=			3
OO_BASEVER=		3.2
OO_RELEASE=		3.2.0
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
EMUL_MODULES.linux=	compat freetype2 x11
EMUL_REQD=		suse>=10.0

EMUL_PKG_FMT=		rpm
RPMFILES=		${WRKSRC}/RPMS/*.rpm
RPM2PKG_PREFIX=		${DESTDIR}${PREFIX}
RPM2PKG_SUBPREFIX=	# empty
RPM2PKG_STAGE=		do-install
RUN_LDCONFIG=		no

USE_TOOLS+=	patch

CHECK_FILES_SKIP+=	${PREFIX}/opt/openoffice.org/basis${OO_BASEVER}/ure-link
CHECK_FILES_SKIP+=	${PREFIX}/opt/openoffice.org${OO_VER}/basis-link

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
DISTNAME=		OOo_${OO_RELEASE}_LinuxIntel_install_en-US
WRKSRC=			${WRKDIR}/OOO320_m12_native_packed-1_en-US.9483
.elif ${EMUL_PLATFORM} == "solaris-i386"
DISTNAME=		OOo_${OO_RELEASE}_Solarisx86_install_en-US
WRKSRC=			${WRKDIR}/OOO320_m12_native_packed-1_en-US.9483/packages
.elif ${EMUL_PLATFORM} == "solaris-sparc"
DISTNAME=		OOo_${OO_RELEASE}_SolarisSparc_install_en-US
WRKSRC=			${WRKDIR}/OOO320_m12_native_packed-1_en-US.9483/packages
.endif

.include "options.mk"

INSTALLATION_DIRS= bin

do-install:
	${PATCH} -d ${DESTDIR}${PREFIX}/opt/openoffice.org${OO_VER}/program < ${FILESDIR}/soffice-patch
	${RM} -f ${DESTDIR}${PREFIX}/opt/openoffice.org${OO_VER}/program/soffice.orig
	${PATCH} -d ${DESTDIR}${PREFIX}/opt/openoffice.org${OO_VER}/program < ${FILESDIR}/spadmin-patch
	${RM} -f ${DESTDIR}${PREFIX}/opt/openoffice.org${OO_VER}/program/spadmin.orig
	uniq ${RPM2PKG_PLIST} | \
		sed -e 's,^@exec mkdir -m 755 -p %D/,@pkgdir,' > ${WRKDIR}/PLIST
.if defined(PKG_JVM) && !empty(PKG_JVM)
	${RM} -f ${DESTDIR}${PREFIX}/bin/soffice
	${SED}  -e "s|@@PREFIX@@|${PREFIX}|g" -e "s|@@OO_VER@@|${OO_VER}|g" \
		-e "s|@@JAVA_HOME@@|${PKG_JAVA_HOME}|g" \
		< ${FILESDIR}/soffice > ${DESTDIR}${PREFIX}/bin/soffice
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/soffice
.else
	${LN} -sf ../opt/openoffice.org${OO_VER}/program/soffice ${DESTDIR}${PREFIX}/bin/soffice
.endif
.for i in scalc sdraw simpress smath spadmin swriter
	${LN} -sf ../opt/openoffice.org${OO_VER}/program/${i} ${DESTDIR}${PREFIX}/bin/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
