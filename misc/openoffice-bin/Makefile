# $NetBSD: Makefile,v 1.22 2007/08/23 18:20:32 jlam Exp $

DISTNAME=		openoffice-bin	# overridden below
PKGNAME=		openoffice-bin-${OO_VER}
PKGREVISION=		3
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_OPENOFFICE:=stable/${OO_VER}/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		openoffice-linux-112-services.rdb.bz2
SITES.openoffice-linux-112-services.rdb.bz2=	\
			http://www.fs.tum.de/~mrauch/OpenOffice/download/ \
			ftp://ftp.NetBSD.org/pub/NetBSD/misc/mrauch/
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}	\
			openoffice-linux-112-services.rdb.bz2

MAINTAINER=		mrauch@NetBSD.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (binary pkg)

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice2-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*

OO_VER=			1.1.5
PLIST_SUBST+=		VER=${OO_VER:Q}
MESSAGE_SUBST+=		VER=${OO_VER}

# Install fails with "_sys_thread_create() failed, errno = 14"
NOT_FOR_PLATFORM+=	NetBSD-*-sparc*

TEMP?=			${WRKDIR}
BUILD_DIRS=		# empty

EMUL_PLATFORMS=		linux-i386
EMUL_PLATFORMS+=	solaris-i386 solaris-sparc
EMUL_MODULES.linux=	compat x11
EMUL_REQD=		suse>=7.3

.include "../../mk/bsd.prefs.mk"

.if ${EMUL_PLATFORM} == "linux-i386"
DISTNAME=		OOo_${OO_VER}_LinuxIntel_install
.elif ${EMUL_PLATFORM} == "solaris-i386"
DISTNAME=		OOo_${OO_VER}_Solarisx86_install
WRKSRC=			${WRKDIR}/OOo_${OO_VER}_Solaris_x86_install
.elif ${EMUL_PLATFORM} == "solaris-sparc"
DISTNAME=		OOo_${OO_VER}_SolarisSparc_install
WRKSRC=			${WRKDIR}/OOo_${OO_VER}_Solaris_Sparc_install
.endif

INSTALLATION_DIRS=	bin

.if ${OPSYS} == "NetBSD"
.PHONY: check-proc-cmdline
pre-install: check-proc-cmdline
check-proc-cmdline:
	if ${TEST} ! -f /proc/curproc/cmdline &&			\
	   ${TEST} ! -f ${OPSYS_EMULDIR}/proc/curproc/cmdline; then	\
		${ECHO} "Please mount ${OPSYS_EMULDIR}/proc or /proc";	\
		exit 1;							\
	fi
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

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/OpenOffice.org${OO_VER}/program
	${INSTALL_DATA} ${WRKDIR}/openoffice-linux-112-services.rdb	\
		${PREFIX}/OpenOffice.org${OO_VER}/program/services.rdb
	cd ${WRKSRC}; ${SETENV} TEMP=${TEMP} ./install --prefix=${PREFIX}
	${RM} -f ${PREFIX}/bin/soffice.orig
	${SED}  -e "s|@@PREFIX@@|${PREFIX}|g" -e "s|@@OO_VER@@|${OO_VER}|g" \
		< ${FILESDIR}/soffice > ${PREFIX}/bin/soffice
	${CHMOD} +x ${PREFIX}/bin/soffice
.for i in scalc sdraw simpress swriter
	${LN} -sf ${PREFIX}/OpenOffice.org${OO_VER}/program/${i} ${PREFIX}/bin/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
