# $NetBSD: Makefile,v 1.28.2.1 2007/06/23 23:32:09 salo Exp $

PKGNAME=		openoffice2-bin-${OO_RELEASE}
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_OPENOFFICE:=stable/${OO_RELEASE}/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		mrauch@NetBSD.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (binary pkg)

BUILD_DEPENDS+=		rpm2pkg>=2.1:../../pkgtools/rpm2pkg

RPM2PKG=		${PREFIX}/sbin/rpm2pkg
RPM2PKGARGS=		-d ${PREFIX} -f ${WRKDIR}/PLIST.nouniq -s 1

OO_VER=			2.2
OO_RELEASE=		2.2.1
PLIST_SUBST+=		VER=${OO_VER:Q}
MESSAGE_SUBST+=		VER=${OO_VER:Q}
FILES_SUBST+=		VER=${OO_VER:Q}

NO_CONFIGURE=		yes
NO_BUILD=		yes

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice-bin-[0-9]*
CONFLICTS+=		openoffice2-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.6*-i386 NetBSD-[2-9]*-i386
ONLY_FOR_PLATFORM+=	Linux-*-i[3-6]86 DragonFly-*-i386

TEMP?=			${WRKSRC}
CHECK_SHLIBS_SUPPORTED=	no

PLIST_SRC=		${PKGDIR}/PLIST.proglinks
PLIST_SRC+=		${WRKDIR}/PLIST

.include "../../mk/bsd.prefs.mk"

# group together i386, i486, i586 and i686 (for Linux)
#
ARCH=	${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if ${OPSYS} == "NetBSD"
DISTNAME=	OOo_${OO_RELEASE}_LinuxIntel_install_en-US
WRKSRC=		${WRKDIR}/OOF680_m18_native_packed-1_en-US.9161
.endif

.if ${OPSYS} == "DragonFly"
DISTNAME=	OOo_${OO_RELEASE}_LinuxIntel_install_en-US
WRKSRC=		${WRKDIR}/OOF680_m18_native_packed-1_en-US.9161
.endif

.if ${OPSYS} == "Linux"
.if ${ARCH} == "i386"
DISTNAME=	OOo_${OO_RELEASE}_LinuxIntel_install_en-US
WRKSRC=		${WRKDIR}/OOF680_m18_native_packed-1_en-US.9161
.endif
.endif

.if ${OPSYS} == "SunOS"
.if ${MACHINE_ARCH} == "sparc" || ${MACHINE_ARCH} == "sparc64"
DISTNAME=	OOo_${OO_RELEASE}_SolarisSparc_install_en-US
WRKSRC=		${WRKDIR}/OOF680_m14_native_packed-1_en-US.9134/packages
.elif ${MACHINE_ARCH} == "i386"
DISTNAME=	OOo_${OO_RELEASE}_Solarisx86_install_en-US
WRKSRC=		${WRKDIR}/OOF680_m14_native_packed-1_en-US.9134/packages
.endif
.endif

# everything specific to your OS/Arch goes into its own Makefile

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.endif

DISTNAME?=	OOo_${OO_RELEASE}_LinuxIntel_install_en-US

.include "options.mk"

do-install:
	${RM} -f ${WRKDIR}/PLIST.nouniq
	${RPM2PKG} ${RPM2PKGARGS} ${WRKSRC}/RPMS/*.rpm
	uniq ${WRKDIR}/PLIST.nouniq >${WRKDIR}/PLIST
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
