# $NetBSD: Makefile,v 1.11 2006/09/20 13:00:02 rillig Exp $
#

DISTNAME=	pkg_alternatives-1.3
PKGREVISION=	1
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Generic wrappers for programs with similar interfaces

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		YES
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
SUBST_FILES.vars=	*
SUBST_SED.vars=		-e 's|@CONFDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.vars+=	-e 's|@DATADIR@|${DATADIR}|g'
SUBST_SED.vars+=	-e 's|@DBDIR@|${DBDIR}|g'
SUBST_SED.vars+=	-e 's|@PKG_DBDIR@|${PKG_DBDIR}|g'
SUBST_SED.vars+=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.vars+=	-e 's|@ROOT_USER@|${ROOT_USER}|g'
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
		${PREFIX}/sbin/pkg_alternatives
	${INSTALL_MAN} ${WRKSRC}/pkg_alternatives.8 ${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/wrapper.sh ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/wrapper.man ${DATADIR}/
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/filter.conf ${EGDIR}/

.include "../../mk/bsd.pkg.mk"
