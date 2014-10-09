# $NetBSD: Makefile,v 1.14 2014/10/09 14:07:02 wiz Exp $
#

DISTNAME=	lq-sp-1.3.4.12
CATEGORIES=	www
MASTER_SITES=	http://www.htmlhelp.com/tools/validator/offline/

MAINTAINER=	norm@sandbox.org.uk
HOMEPAGE=	http://www.htmlhelp.com/tools/validator/offline/
COMMENT=	Modified SP package

USE_LANGUAGES=	c c++

# doesn't build (LP64 bugs)
NOT_FOR_PLATFORM=	*-*-alpha

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e 's,/usr/local,${PREFIX},g'

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsgmls/lq-nsgmls ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
