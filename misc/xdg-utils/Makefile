# $NetBSD: Makefile,v 1.9 2016/06/13 21:40:22 youri Exp $

DISTNAME=	xdg-utils-1.1.1
PKGNAME=	${DISTNAME:S/-rc/rc/}
CATEGORIES=	misc
MASTER_SITES=	http://portland.freedesktop.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://portland.freedesktop.org/
COMMENT=	Tools to assist applications with various desktop integration tasks
LICENSE=	mit

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=	w3m-[0-9]*:../../www/w3m

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run gmake gsed:run

SUBST_CLASSES+=		gsed
SUBST_FILES.gsed=	scripts/xdg-*
SUBST_STAGE.gsed=	post-build
SUBST_MESSAGE.gsed=	Use GNU sed instead of sed.
SUBST_SED.gsed+=	-e "s/sed /gsed /g"

# "foo > /dev/null 2> /dev/null" gives "foo: not found" with NetBSD's sh
REPLACE_BASH+=	scripts/xdg-*

.include "../../mk/bsd.pkg.mk"
