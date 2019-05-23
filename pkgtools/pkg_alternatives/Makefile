# $NetBSD: Makefile,v 1.23 2019/05/23 19:23:12 rillig Exp $
#

PKGNAME=	pkg_alternatives-1.6
CATEGORIES=	pkgtools

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Generic wrappers for programs with similar interfaces
LICENSE=	modified-bsd

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
SUBST_VARS.vars=	DATADIR
SUBST_VARS.vars+=	DBDIR
SUBST_VARS.vars+=	PKGMANDIR
SUBST_VARS.vars+=	PKG_DBDIR
SUBST_VARS.vars+=	PREFIX
SUBST_SED.vars+=	-e 's|@ROOT_USER@|${REAL_ROOT_USER}|g'
SUBST_VARS.vars+=	ID
SUBST_VARS.vars+=	SH

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
