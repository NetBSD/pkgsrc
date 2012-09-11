# $NetBSD: Makefile,v 1.19 2012/09/11 23:19:36 asau Exp $
#

DISTNAME=	pkg_alternatives-1.6
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Generic wrappers for programs with similar interfaces

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=		YES
WRKSRC=			${WRKDIR}

DATADIR=		${PREFIX}/share/pkg_alternatives
DBDIR=			${PREFIX}/libdata/pkg_alternatives
EGDIR=			${PREFIX}/share/examples/pkg_alternatives

FILES_SUBST+=		PKG_ALTERNATIVES=${PREFIX}/sbin/pkg_alternatives

REQD_DIRS=		${DBDIR}
MAKE_DIRS=		${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	pkg_alternatives
CONF_FILES=		${EGDIR}/filter.conf ${PKG_SYSCONFDIR}/filter.conf

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	do-configure
SUBST_MESSAGE.vars=	Configuring sources.
SUBST_FILES.vars=	pkg_alternatives.8 pkg_alternatives.sh
SUBST_SED.vars=		-e 's|@CONFDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.vars+=	-e 's|@DATADIR@|${DATADIR}|g'
SUBST_SED.vars+=	-e 's|@DBDIR@|${DBDIR}|g'
SUBST_SED.vars+=	-e 's|@PKGMANDIR@|${PKGMANDIR}|g'
SUBST_SED.vars+=	-e 's|@PKG_DBDIR@|${PKG_DBDIR}|g'
SUBST_SED.vars+=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.vars+=	-e 's|@ROOT_USER@|${REAL_ROOT_USER}|g'
SUBST_SED.vars+=	-e 's|@ID@|${ID}|g'
SUBST_SED.vars+=	-e 's|@SH@|${SH}|g'

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

CHECK_INTERPRETER_SKIP=	${DATADIR}/wrapper.sh

do-extract:
	${CP} ${FILESDIR}/pkg_alternatives.sh ${WRKSRC}
	${CP} ${FILESDIR}/pkg_alternatives.8 ${WRKSRC}
	${CP} ${FILESDIR}/wrapper.sh ${WRKSRC}
	${CP} ${FILESDIR}/wrapper.man ${WRKSRC}
	${CP} ${FILESDIR}/filter.conf ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_alternatives.sh \
		${DESTDIR}${PREFIX}/sbin/pkg_alternatives
	${INSTALL_MAN} ${WRKSRC}/pkg_alternatives.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA_DIR} ${DESTDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/wrapper.sh ${DESTDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/wrapper.man ${DESTDIR}${DATADIR}/
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/filter.conf ${DESTDIR}${EGDIR}/

.include "../../mk/bsd.pkg.mk"
