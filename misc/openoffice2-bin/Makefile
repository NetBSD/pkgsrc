# $NetBSD: Makefile,v 1.35 2008/04/20 13:17:55 tron Exp $

DISTNAME=		openoffice2-bin	# overridden below
PKGNAME=		openoffice2-bin-${OO_RELEASE}
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_OPENOFFICE:=stable/${OO_RELEASE}/}

MAINTAINER=		mrauch@NetBSD.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (binary pkg)

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice-bin-[0-9]*
CONFLICTS+=		openoffice2-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*

OO_VER=			2.4
OO_RELEASE=		2.4.0
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
EMUL_REQD=		suse>=7.3

EMUL_PKG_FMT=		rpm
RPMFILES=		${WRKSRC}/RPMS/*.rpm
RPM2PKG_PREFIX=		${PREFIX}
RPM2PKG_SUBPREFIX=	# empty
RPM2PKG_STAGE=		do-install
RUN_LDCONFIG=		no

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
DISTNAME=		OOo_${OO_RELEASE}_LinuxIntel_install_en-US
WRKSRC=			${WRKDIR}/OOH680_m12_native_packed-1_en-US.9286
.elif ${EMUL_PLATFORM} == "solaris-i386"
DISTNAME=		OOo_${OO_RELEASE}_Solarisx86_install_en-US
WRKSRC=			${WRKDIR}/OOG680_m5_native_packed-1_en-US.9221/packages
.elif ${EMUL_PLATFORM} == "solaris-sparc"
DISTNAME=		OOo_${OO_RELEASE}_SolarisSparc_install_en-US
WRKSRC=			${WRKDIR}/OOG680_m5_native_packed-1_en-US.9221/packages
.endif

.include "options.mk"

do-install:
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
.for i in scalc sdraw simpress swriter
	${LN} -sf ../openoffice.org${OO_VER}/program/${i} ${PREFIX}/bin/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
