# $NetBSD: Makefile,v 1.1.1.1 2002/11/28 19:57:28 jmmv Exp $
#

DISTNAME=	sysbuild-1.0
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@netbsd.org
COMMENT=	Automate NetBSD system and kernel unprivileged builds

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATH=	yes
NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}
CHECK_SHLIBS=	no
SHLIB_HANDLING=	no

.include "../../mk/bsd.prefs.mk"

# SYSBUILD_HOME		- Home directory of SYSBUILD_USER user.
SYSBUILD_HOMEDIR?=	/home/sysbuild
# SYSBUILD_USER		- Unpriviledged user that runs the build script.
SYSBUILD_USER?=		sysbuild
# SYSBUILD_OBJGROUP	- Group that owns build files (should not be shared).
SYSBUILD_OBJGROUP?=	wobj
# SYSBUILD_SRCGROUP	- Group that owns sources (may be shared).
SYSBUILD_SRCGROUP?=	wsrc

FILES_SUBST+=		SYSBUILD_HOMEDIR=${SYSBUILD_HOMEDIR}
FILES_SUBST+=		SYSBUILD_USER=${SYSBUILD_USER}
FILES_SUBST+=		SYSBUILD_OBJGROUP=${SYSBUILD_OBJGROUP}
FILES_SUBST+=		SYSBUILD_SRCGROUP=${SYSBUILD_SRCGROUP}
FILES_SUBST+=		EGDIR=${EGDIR}
MESSAGE_SUBST+=		SYSBUILD_USER=${SYSBUILD_USER}

DEINSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL

PKG_GROUPS=		${SYSBUILD_OBJGROUP} ${SYSBUILD_SRCGROUP}
PKG_USERS=		${SYSBUILD_USER}:${SYSBUILD_OBJGROUP}::`hostname`\\ sysbuild\\ output:${SYSBUILD_HOMEDIR}:${SH}

EGDIR=			${PREFIX}/share/examples/sysbuild

do-build:
	@${ECHO} "Generating sysbuild.sh..."
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/sysbuild.sh > \
	        ${WRKSRC}/sysbuild.sh
	@${ECHO} "Generating sysbuild.8..."
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/sysbuild.8 > \
	        ${WRKSRC}/sysbuild.8
	@${ECHO} "Generating sample default.conf..."
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/default.conf > \
	        ${WRKSRC}/default.conf
	@${ECHO} "Generating sample crontab..."
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/crontab > ${WRKSRC}/crontab

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sysbuild
	${INSTALL_SCRIPT} ${WRKSRC}/sysbuild.sh ${PREFIX}/bin/sysbuild
	${INSTALL_MAN} ${WRKSRC}/sysbuild.8 ${PREFIX}/man/man8/sysbuild.8
	${INSTALL_DATA} ${WRKSRC}/default.conf ${EGDIR}/default.conf
	${INSTALL_DATA} ${WRKSRC}/crontab ${EGDIR}/crontab

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
