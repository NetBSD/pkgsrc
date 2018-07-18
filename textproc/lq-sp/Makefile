# $NetBSD: Makefile,v 1.16 2018/07/18 00:06:24 joerg Exp $
#

DISTNAME=	lq-sp-1.3.4.12
CATEGORIES=	www
MASTER_SITES=	http://www.htmlhelp.com/tools/validator/offline/

MAINTAINER=	norm@sandbox.org.uk
HOMEPAGE=	http://www.htmlhelp.com/tools/validator/offline/
COMMENT=	Modified SP package

USE_LANGUAGES=	c c++03

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e 's,/usr/local,${PREFIX},g'

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsgmls/lq-nsgmls ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
