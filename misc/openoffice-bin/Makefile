# $NetBSD: Makefile,v 1.3 2005/02/27 11:14:49 wiz Exp $

PKGNAME=		openoffice-bin-${OO_VER}
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_OPENOFFICE:=stable/${OO_VER}/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		openoffice-linux-112-services.rdb.bz2
SITES_openoffice-linux-112-services.rdb.bz2=http://www.fs.tum.de/~mrauch/OpenOffice/download/\
			ftp://ftp.NetBSD.org/pub/NetBSD/misc/mrauch/

MAINTAINER=		mrauch@NetBSD.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (binary pkg)

OO_VER=		1.1.4
PLIST_SUBST+=	VER=${OO_VER}
MESSAGE_SUBST+=	VER=${OO_VER}

NO_CONFIGURE=           yes

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.6*-i386 NetBSD-[2-9]*-i386
# Install fails with "_sys_thread_create() failed, errno = 14"
#ONLY_FOR_PLATFORM+=	NetBSD-1.6*-sparc* NetBSD-[2-9]*-sparc*
ONLY_FOR_PLATFORM+=	Linux-*-i[3-6]86
ONLY_FOR_PLATFORM+=	SunOS-*-*

TEMP?=			${WRKSRC}
CHECK_SHLIBS=		no

.include "../../mk/bsd.prefs.mk"

do-build:

.if ${OPSYS} == "NetBSD"
USE_PKGINSTALL=         yes

.  if ${MACHINE_ARCH} == "sparc" || ${MACHINE_ARCH} == "sparc64"
.    if !exists(/emul/svr4/usr/lib/ld.so)
PKG_FAIL_REASON= '${PKGNAME} requires Solaris libraries - see compat_svr4(8)'
.    endif
DISTNAME=	OOo_${OO_VER}_SolarisSparc_install
WRKSRC=		${WRKDIR}/OOo_${OO_VER}_Solaris_Sparc_install
.  elif ${MACHINE_ARCH} == "i386"
DISTNAME=	OOo_${OO_VER}_LinuxIntel_install
SUPPORT_FILES=          /dev/null /emul/linux/etc/mtab
.  endif

.endif

.if ${OPSYS} == "SunOS"
.if ${MACHINE_ARCH} == "sparc" || ${MACHINE_ARCH} == "sparc64"
DISTNAME=	OOo_${OO_VER}_SolarisSparc_install
WRKSRC=		${WRKDIR}/OOo_${OO_VER}_Solaris_Sparc_install
.elif ${MACHINE_ARCH} == "i386"
DISTNAME=	OOo_${OO_VER}_SolarisIntel_install
WRKSRC=		${WRKDIR}/OOo_${OO_VER}_Solaris_Intel_install
# I don't have a Solaris/Intel box to test the PLIST out
PKG_FAIL_REASON= '${PKGNAME} needs to have the PLIST fixed up still'
.endif
.endif

pre-install:
	${CP} ${WRKSRC}/setup.ins ${WRKSRC}/setup.ins.orig
	${SED}  -e "s|/usr/bin/soffice|${PREFIX}/bin/soffice.orig|g"	\
		-e "s|not(existsFile(searchdir, searchfile))|true|g"	\
		<${WRKSRC}/setup.ins.orig >${WRKSRC}/setup.ins
.if !exists(${WRKSRC}/install)
	${CP} ${FILESDIR}/install ${WRKSRC}/install
	${CHMOD} +x ${WRKSRC}/install
.endif
#.     if ${OPSYS}=="NetBSD" && !exists(/emul/linux/etc/mtab)
#	${CP} /dev/null /emul/linux/etc/mtab
#.     endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/OpenOffice.org${OO_VER}/program
	${INSTALL_DATA} ${WRKDIR}/openoffice-linux-112-services.rdb	\
		${PREFIX}/OpenOffice.org${OO_VER}/program/services.rdb
	${SH} -c "cd ${WRKSRC}; ./install --prefix=${PREFIX}"
	${RM} -f ${PREFIX}/bin/soffice.orig
	${SED}  -e "s|@@PREFIX@@|${PREFIX}|g" -e "s|@@OO_VER@@|${OO_VER}|g" \
		< ${FILESDIR}/soffice > ${PREFIX}/bin/soffice
	${CHMOD} +x ${PREFIX}/bin/soffice
.for i in scalc sdraw simpress swriter
	${LN} -sf ${PREFIX}/OpenOffice.org${OO_VER}/program/$i ${PREFIX}/bin/$i
.endfor

# everything specific to your OS/Arch goes into its own Makefile
# group together i386, i486, i586 and i686 (for Linux)
#
ARCH=	${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.endif

.if ${DISTNAME} == "OOo_${OO_VER}_SolarisSparc_install"
PLIST_SRC=	${PKGDIR}/PLIST.SolarisSparc
.elif ${DISTNAME} == "OOo_${OO_VER}_SolarisIntel_install"
PLIST_SRC=	${PKGDIR}/PLIST.SolarisIntel
.elif ${DISTNAME} == "OOo_${OO_VER}_LinuxIntel_install"
PLIST_SRC=	${PKGDIR}/PLIST.LinuxIntel
.else
PKG_FAIL_REASON= '${PKGNAME}:  cannot figure out which PLIST to use'
.endif

.include "../../mk/bsd.pkg.mk"
