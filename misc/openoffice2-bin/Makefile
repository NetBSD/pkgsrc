# $NetBSD: Makefile,v 1.19 2006/05/22 22:22:04 jlam Exp $

PKGNAME=		openoffice-bin-2.0.2
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_OPENOFFICE:=stable/2.0.2/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		mrauch@NetBSD.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (binary pkg)

BUILD_DEPENDS+=		rpm2pkg>=2.1:../../pkgtools/rpm2pkg

RPM2PKG=		${PREFIX}/sbin/rpm2pkg
RPM2PKGARGS=		-d ${PREFIX} -f ${WRKDIR}/PLIST.nouniq -s 1

OO_VER=			2.0
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

DEINSTALL_TEMPLATE+=	${PKGDIR}/INSTALL

.if ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "sparc" || ${MACHINE_ARCH} == "sparc64"
.    if !exists(/emul/svr4/usr/lib/ld.so)
PKG_FAIL_REASON+=	'${PKGNAME} requires Solaris libraries - see compat_svr4(8)'
.    endif
DISTNAME=	OOo_2.0.2_SolarisSparc_install
WRKSRC=		${WRKDIR}/OOB680_m5_native_packed-1_en-US.9011/packages
.  elif ${MACHINE_ARCH} == "i386"
DISTNAME=	OOo_2.0.2_LinuxIntel_install
WRKSRC=		${WRKDIR}/OOB680_m5_native_packed-1_en-US.9011/RPMS
.  endif
.endif

.if ${OPSYS} == "DragonFly"
DISTNAME=	OOo_2.0.2_LinuxIntel_install
WRKSRC=		${WRKDIR}/OOB680_m5_native_packed-1_en-US.9011/RPMS
.endif

.if ${OPSYS} == "Linux"
.if ${ARCH} == "i386"
DISTNAME=	OOo_2.0.2_LinuxIntel_install
WRKSRC=		${WRKDIR}/OOB680_m5_native_packed-1_en-US.9011/RPMS
.endif
.endif

.if ${OPSYS} == "SunOS"
.if ${MACHINE_ARCH} == "sparc" || ${MACHINE_ARCH} == "sparc64"
DISTNAME=	OOo_2.0.2_SolarisSparc_install
WRKSRC=		${WRKDIR}/OOB680_m5_native_packed-1_en-US.9011/packages
.elif ${MACHINE_ARCH} == "i386"
DISTNAME=	OOo_2.0.2_Solarisx86_install
WRKSRC=		${WRKDIR}/OOB680_m5_native_packed-1_en-US.9011/packages
.endif
.endif

# everything specific to your OS/Arch goes into its own Makefile

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.endif

.if !defined(DISTNAME)
DISTNAME=	# Dummy to prevent error from missing DISTNAME
.endif

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
