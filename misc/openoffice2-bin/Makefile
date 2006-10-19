# $NetBSD: Makefile,v 1.23 2006/10/19 19:53:37 wiz Exp $

PKGNAME=		openoffice-bin-${OO_RELEASE}
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_OPENOFFICE:=stable/${OO_RELEASE}/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		mrauch@NetBSD.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (binary pkg)

BUILD_DEPENDS+=		rpm2pkg>=2.1:../../pkgtools/rpm2pkg

RPM2PKG=		${PREFIX}/sbin/rpm2pkg
RPM2PKGARGS=		-d ${PREFIX} -f ${WRKDIR}/PLIST.nouniq -s 1

OO_VER=			2.0
OO_RELEASE=		2.0.4
PLIST_SUBST+=		VER=${OO_VER:Q}
MESSAGE_SUBST+=		VER=${OO_VER:Q}
FILES_SUBST+=		VER=${OO_VER:Q}

NO_CONFIGURE=           yes
NO_BUILD=		yes

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice2-bin-[0-9]*
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
.  if ${MACHINE_ARCH} == "sparc" || ${MACHINE_ARCH} == "sparc64"
.    if !exists(/emul/svr4/usr/lib/ld.so)
PKG_FAIL_REASON+=	'${PKGNAME} requires Solaris libraries - see compat_svr4(8)'
.    endif
DISTNAME=	OOo_${OO_RELEASE}_SolarisSparc_install
WRKSRC=		${WRKDIR}/OOD680_m5_native_packed-1_en-US.9073/packages
.  elif ${MACHINE_ARCH} == "i386"
DISTNAME=	OOo_${OO_RELEASE}_LinuxIntel_install
WRKSRC=		${WRKDIR}/OOD680_m5_native_packed-1_en-US.9073/RPMS
.  endif
.endif

.if ${OPSYS} == "DragonFly"
DISTNAME=	OOo_${OO_RELEASE}_LinuxIntel_install
WRKSRC=		${WRKDIR}/OOD680_m5_native_packed-1_en-US.9073/RPMS
.endif

.if ${OPSYS} == "Linux"
.if ${ARCH} == "i386"
DISTNAME=	OOo_${OO_RELEASE}_LinuxIntel_install
WRKSRC=		${WRKDIR}/OOD680_m5_native_packed-1_en-US.9073/RPMS
.endif
.endif

.if ${OPSYS} == "SunOS"
.if ${MACHINE_ARCH} == "sparc" || ${MACHINE_ARCH} == "sparc64"
DISTNAME=	OOo_${OO_RELEASE}_SolarisSparc_install
WRKSRC=		${WRKDIR}/OOD680_m5_native_packed-1_en-US.9073/packages
.elif ${MACHINE_ARCH} == "i386"
DISTNAME=	OOo_${OO_RELEASE}_Solarisx86_install
WRKSRC=		${WRKDIR}/OOD680_m5_native_packed-1_en-US.9073/packages
.endif
.endif

# everything specific to your OS/Arch goes into its own Makefile

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.endif

DISTNAME?=	OOo_${OO_RELEASE}_LinuxIntel_install

.include "options.mk"

do-install:
	${RM} -f ${WRKDIR}/PLIST.nouniq
	${RPM2PKG} ${RPM2PKGARGS} ${WRKSRC}/*.rpm
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
