# $NetBSD: Makefile,v 1.3 2009/12/07 22:07:23 bad Exp $

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
OO_BASEVER=		3.1
OO_RELEASE=		3.1.1
PLIST_SUBST+=		VER=${OO_VER:Q}
MESSAGE_SUBST+=		VER=${OO_VER:Q}
FILES_SUBST+=		VER=${OO_VER:Q}

TEMP?=			${WRKSRC}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
BUILD_DIRS=		# empty

PLIST_SRC=		${PKGDIR}/PLIST.proglinks
PLIST_SRC+=		${WRKDIR}/PLIST

EMUL_PLATFORMS=		linux-i386
#EMUL_PLATFORMS+=	solaris-i386 solaris-sparc
EMUL_MODULES.linux=	compat freetype2 x11
EMUL_REQD=		suse>=10.0

EMUL_PKG_FMT=		rpm
RPMFILES=		${WRKSRC}/RPMS/*.rpm
RPM2PKG_PREFIX=		${PREFIX}
RPM2PKG_SUBPREFIX=	# empty
RPM2PKG_STAGE=		do-install
RUN_LDCONFIG=		no

USE_TOOLS+=	patch

CHECK_FILES_SKIP+=	${PREFIX}/openoffice.org/basis${OO_BASEVER}/ure-link
CHECK_FILES_SKIP+=	${PREFIX}/openoffice.org${OO_VER}/basis-link

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
DISTNAME=		OOo_${OO_RELEASE}_LinuxIntel_install_en-US
WRKSRC=			${WRKDIR}/OOO310_m19_native_packed-1_en-US.9420
.elif ${EMUL_PLATFORM} == "solaris-i386"
DISTNAME=		OOo_${OO_RELEASE}_Solarisx86_install_en-US
WRKSRC=			${WRKDIR}/OOO310_m19_native_packed-1_en-US.9420/packages
.elif ${EMUL_PLATFORM} == "solaris-sparc"
DISTNAME=		OOo_${OO_RELEASE}_SolarisSparc_install_en-US
WRKSRC=			${WRKDIR}/OOO310_m19_native_packed-1_en-US.9420/packages
.endif

.include "options.mk"

do-install:
	${PATCH} -d ${PREFIX}/openoffice.org${OO_VER}/program < ${FILESDIR}/soffice-patch
	${RM} -f ${PREFIX}/openoffice.org${OO_VER}/program/soffice.orig
	${PATCH} -d ${PREFIX}/openoffice.org${OO_VER}/program < ${FILESDIR}/spadmin-patch
	${RM} -f ${PREFIX}/openoffice.org${OO_VER}/program/spadmin.orig
	uniq ${RPM2PKG_PLIST} > ${WRKDIR}/PLIST
.if defined(PKG_JVM) && !empty(PKG_JVM)
	${RM} -f ${PREFIX}/bin/soffice
	${SED}  -e "s|@@PREFIX@@|${PREFIX}|g" -e "s|@@OO_VER@@|${OO_VER}|g" \
		-e "s|@@JAVA_HOME@@|${PKG_JAVA_HOME}|g" \
		< ${FILESDIR}/soffice > ${PREFIX}/bin/soffice
	${CHMOD} +x ${PREFIX}/bin/soffice
.else
	${LN} -sf ../openoffice.org${OO_VER}/program/soffice ${PREFIX}/bin/soffice
.endif
.for i in scalc sdraw simpress smath spadmin swriter
	${LN} -sf ../openoffice.org${OO_VER}/program/${i} ${PREFIX}/bin/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
