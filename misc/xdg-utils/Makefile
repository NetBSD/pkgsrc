# $NetBSD: Makefile,v 1.13 2018/05/12 10:11:49 leot Exp $

DISTNAME=	xdg-utils-1.1.3
CATEGORIES=	misc
MASTER_SITES=	https://portland.freedesktop.org/download/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/xdg-utils/
COMMENT=	Tools to assist applications with various desktop integration tasks
LICENSE=	mit

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=	w3m-[0-9]*:../../www/w3m

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run gmake grep:run gsed:run

SUBST_CLASSES+=		gsed
SUBST_FILES.gsed=	scripts/xdg-*.in
SUBST_STAGE.gsed=	pre-configure
SUBST_MESSAGE.gsed=	Use GNU grep/sed instead of grep/sed.
SUBST_SED.gsed+=	-e "s, sed , ${TOOLS_PATH.gsed} ,g"
SUBST_SED.gsed+=	-e "s, grep , ${TOOLS_PATH.grep} ,g"

# "foo > /dev/null 2> /dev/null" gives "foo: not found" with NetBSD's sh
REPLACE_BASH+=	scripts/xdg-*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
TOOLS_PLATFORM.grep=	# use pkgsrc ggrep
.endif

.include "../../mk/bsd.pkg.mk"
