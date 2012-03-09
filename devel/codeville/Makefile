# $NetBSD: Makefile,v 1.24 2012/03/09 12:34:05 wiz Exp $

DISTNAME=	Codeville-0.8.0
PKGNAME=	codeville-0.8.0
PKGREVISION=	6
CATEGORIES=	devel scm
MASTER_SITES=	http://codeville.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://codeville.org/
COMMENT=	Distributed revision control system
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PYTHON=		*.py
REPLACE_PYTHON+=	*/*.py

BUILD_DEFS+=		VARBASE
BUILD_DEFS_EFFECTS+=	CODEVILLE_DATADIR
CODEVILLE_DATADIR?=	${VARBASE}/db/cdv

# XXX Could create a user for the server, rc script, server directory hier, etc.

CONF_FILES=		${EGDIR}/cdvserver.conf  \
			${PKG_SYSCONFDIR}/cdvserver.conf

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	cdvserver.conf.sample cdvpasswd cdvserver
SUBST_MESSAGE.paths=	performing pathname substitutions
SUBST_STAGE.paths=	pre-configure
SUBST_VARS.paths=	CODEVILLE_DATADIR VARBASE PKG_SYSCONFDIR

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/cdvserver.conf.sample \
		${DESTDIR}${EGDIR}/cdvserver.conf

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
