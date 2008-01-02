# $NetBSD: Makefile,v 1.78 2008/01/02 09:00:34 adrianp Exp $

DISTNAME=	audit-packages-1.46
CATEGORIES=	security pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@NetBSD.org
COMMENT=	Tools to show vulnerabilities in installed packages

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	pkg_install>=20070714

USE_TOOLS+=	digest:run

BUILD_DEFS+=	PKGVULNDIR

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes

OWN_DIRS=	${PKGVULNDIR}
MAN8DIR=	${PREFIX}/${PKGMANDIR}/man8
CAT8DIR=	${PREFIX}/${PKGMANDIR}/cat8
INSTALLATION_DIRS=	${CAT8DIR} ${MAN8DIR} sbin \
			share/examples/audit-packages

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
MESSAGE_SRC=	${PKGDIR}/MESSAGE.DragonFly
.else
MESSAGE_SRC=	${PKGDIR}/MESSAGE
.endif

# If you're running NetBSD it's possible that you may already have
# audit-packages installed as a part of the base OS.
#
.if ${OPSYS} == "NetBSD"
.	if exists(/usr/sbin/audit-packages)
PKG_FAIL_REASON+=	"audit-packages is already installed on this system"
.	endif
.endif

CONF_FILES=	${PREFIX}/share/examples/audit-packages/audit-packages.conf \
		${PKG_SYSCONFDIR}/audit-packages.conf

SUBST_CLASSES=		paths
SUBST_STAGE.paths=	post-build
SUBST_FILES.paths=	audit-packages audit-packages.0 audit-packages.8
SUBST_FILES.paths+=	download-vulnerability-list
SUBST_SED.paths=	-e 's|@PKGVULNDIR@|${PKGVULNDIR}|g'
SUBST_SED.paths+=	-e 's|@AWK@|${AWK}|g'
SUBST_SED.paths+=	-e 's|@FETCH_CMD@|${FETCH_CMD:Q}|g'
SUBST_SED.paths+=	-e 's|@FETCH_CMD_SHORT@|${FETCH_CMD:T:Q}|g'
SUBST_SED.paths+=	-e 's|@PKGSRCDIR@|${PKGSRCDIR}|g'
SUBST_SED.paths+=	-e 's|@PKG_TOOLS_BIN@|${PKG_TOOLS_BIN}|g'
SUBST_SED.paths+=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.paths+=	-e 's|@SH@|${SH}|g'
SUBST_SED.paths+=	-e 's|@DIGEST@|${DIGEST}|g'
SUBST_SED.paths+=	-e 's|@CHMOD@|${CHMOD}|g'
SUBST_SED.paths+=	-e 's|@MV@|${MV}|g'
SUBST_SED.paths+=	-e 's|@RM@|${RM}|g'
SUBST_SED.paths+=	-e 's|@MKDIR@|${MKDIR}|g'
SUBST_SED.paths+=	-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.paths+=	-e 's|@FIND@|${FIND}|g'
SUBST_MESSAGE.paths=	Fixing paths.

.if ${OPSYS} == "SunOS" || ${OPSYS} == "AIX"
USE_TOOLS+=	nroff
.endif

do-build:
	for f in audit-packages audit-packages.0 audit-packages.8 	\
		download-vulnerability-list; do				\
		${CP} ${FILESDIR}/$$f ${WRKSRC} ;			\
	done

.if ${OPSYS} == "SunOS" || ${OPSYS} == "AIX"
	# pre-created man-pages are "mandoc" pages, these OS need "man",
	# so regen the .0 page
	${NROFF} -man ${WRKSRC}/audit-packages.8 >${WRKSRC}/audit-packages.0
.endif

do-install:
	${INSTALL_DATA} ${FILESDIR}/audit-packages.conf \
		${DESTDIR}${PREFIX}/share/examples/audit-packages

	for f in audit-packages download-vulnerability-list; do	\
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/sbin; \
	done

	${INSTALL_MAN} ${WRKSRC}/audit-packages.0 ${DESTDIR}${CAT8DIR}/
	${INSTALL_MAN} ${WRKSRC}/audit-packages.8 ${DESTDIR}${MAN8DIR}/

	${RM} -f ${DESTDIR}${CAT8DIR}/download-vulnerability-list.0
	${LN} -s audit-packages.0 ${DESTDIR}${CAT8DIR}/download-vulnerability-list.0
	${RM} -f ${DESTDIR}${MAN8DIR}/download-vulnerability-list.8
	${LN} -s audit-packages.8 ${DESTDIR}${MAN8DIR}/download-vulnerability-list.8

.include "../../mk/bsd.pkg.mk"
