# $NetBSD: Makefile,v 1.4 2005/02/10 10:18:03 jmmv Exp $
#

DISTNAME=	pkg_alternatives-1.3
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Generic wrappers for programs with similar interfaces

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		YES
NO_BUILD=		YES
NO_BUILDLINK=		YES
USE_PKGINSTALL=		YES
WRKSRC=			${WRKDIR}

DATADIR=		${PREFIX}/share/pkg_alternatives
DBDIR=			${PREFIX}/libdata/pkg_alternatives
EGDIR=			${PREFIX}/share/examples/pkg_alternatives

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
FILES_SUBST+=		PKG_ALTERNATIVES=${PREFIX}/sbin/pkg_alternatives

MAKE_DIRS=		${DBDIR}
MAKE_DIRS+=		${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	pkg_alternatives
CONF_FILES=		${EGDIR}/filter.conf ${PKG_SYSCONFDIR}/filter.conf

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	do-configure
SUBST_MESSAGE.vars=	"Configuring sources."
SUBST_FILES.vars=	${WRKSRC}/*
SUBST_SED.vars=		-e 's|@CONFDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.vars+=	-e 's|@DATADIR@|${DATADIR}|g'
SUBST_SED.vars+=	-e 's|@DBDIR@|${DBDIR}|g'
SUBST_SED.vars+=	-e 's|@PKG_DBDIR@|${PKG_DBDIR}|g'
SUBST_SED.vars+=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.vars+=	-e 's|@ROOT_USER@|${ROOT_USER}|g'
SUBST_SED.vars+=	-e 's|@SH@|${SH}|g'

INSTALLATION_DIRS=	man/man8 sbin

do-extract:
	${CP} ${FILESDIR}/pkg_alternatives.sh ${WRKSRC}
	${CP} ${FILESDIR}/pkg_alternatives.8 ${WRKSRC}
	${CP} ${FILESDIR}/wrapper.sh ${WRKSRC}
	${CP} ${FILESDIR}/wrapper.man ${WRKSRC}
	${CP} ${FILESDIR}/filter.conf ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_alternatives.sh \
		${PREFIX}/sbin/pkg_alternatives
	${INSTALL_MAN} ${WRKSRC}/pkg_alternatives.8 ${PREFIX}/man/man8/
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/wrapper.sh ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/wrapper.man ${DATADIR}/
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/filter.conf ${EGDIR}/

.include "../../mk/bsd.pkg.mk"
