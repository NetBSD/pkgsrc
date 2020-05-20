# $NetBSD: Makefile,v 1.18 2020/05/20 06:09:06 rillig Exp $
#

DISTNAME=	lq-sp-1.3.4.12
CATEGORIES=	www
MASTER_SITES=	http://www.htmlhelp.com/tools/validator/offline/

MAINTAINER=	norm@sandbox.org.uk
HOMEPAGE=	https://www.htmlhelp.com/tools/validator/offline/
COMMENT=	Modified SP package

USE_LANGUAGES=	c c++03

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e 's,/usr/local,${PREFIX},g'

INSTALLATION_DIRS+=	bin

# CmdLineApp.cxx: In member function 'StringC CmdLineApp::usageString()':
# CmdLineApp.cxx:115:35: error: array subscript has type 'char' [-Werror=char-subscripts]
#      else if (!hadOption[optstr_[i]]) {
#                                   ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nsgmls/lq-nsgmls ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
