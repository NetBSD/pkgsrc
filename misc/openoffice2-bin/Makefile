# $NetBSD: Makefile,v 1.43 2011/03/08 12:10:01 obache Exp $

DISTNAME=		openoffice2-bin	# overridden below
PKGNAME=		openoffice2-bin-${OO_RELEASE}
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_OPENOFFICE:=stable/${OO_RELEASE}/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (binary pkg)

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice-bin-[0-9]*
CONFLICTS+=		openoffice3-bin-[0-9]*
CONFLICTS+=		openoffice2-[0-9]*
CONFLICTS+=		openoffice3-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

OO_VER=			2.4
OO_RELEASE=		2.4.3
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
RPM2PKG_PREFIX=		${DESTDIR}${PREFIX}
RPM2PKG_SUBPREFIX=	# empty
RPM2PKG_STAGE=		do-install
RUN_LDCONFIG=		no

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
DISTNAME=		OOo_${OO_RELEASE}_LinuxIntel_install_en-US
WRKSRC=			${WRKDIR}/OOH680_m21_native_packed-2_en-US.9421
.elif ${EMUL_PLATFORM} == "solaris-i386"
DISTNAME=		OOo_${OO_RELEASE}_Solarisx86_install_en-US
WRKSRC=			${WRKDIR}/OOH680_m21_native_packed-1_en-US.9421/packages
.elif ${EMUL_PLATFORM} == "solaris-sparc"
DISTNAME=		OOo_${OO_RELEASE}_SolarisSparc_install_en-US
WRKSRC=			${WRKDIR}/OOH680_m21_native_packed-1_en-US.9421/packages
.endif

INSTALLATION_DIRS=	bin

.include "options.mk"

do-install:
	uniq ${RPM2PKG_PLIST} > ${WRKDIR}/PLIST
.if defined(PKG_JVM) && !empty(PKG_JVM)
	${RM} -f ${DESTDIR}${PREFIX}/bin/soffice
	${SED}  -e "s|@@PREFIX@@|${PREFIX}|g" -e "s|@@OO_VER@@|${OO_VER}|g" \
		-e "s|@@JAVA_HOME@@|${PKG_JAVA_HOME}|g" \
		< ${FILESDIR}/soffice > ${DESTDIR}${PREFIX}/bin/soffice
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/soffice
.else
	${LN} -sf ../openoffice.org${OO_VER}/program/soffice ${DESTDIR}${PREFIX}/bin/soffice
.endif
.for i in scalc sdraw simpress smath spadmin swriter
	${LN} -sf ../openoffice.org${OO_VER}/program/${i} ${DESTDIR}${PREFIX}/bin/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
