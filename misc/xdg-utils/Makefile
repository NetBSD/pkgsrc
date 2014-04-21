# $NetBSD: Makefile,v 1.7 2014/04/21 15:35:27 wiz Exp $

DISTNAME=	xdg-utils-1.1.0-rc1
PKGNAME=	${DISTNAME:S/-rc/rc/}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://portland.freedesktop.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://portland.freedesktop.org/
COMMENT=	Tools to assist applications with various desktop integration tasks
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run gsed:run

SUBST_CLASSES+=		gsed
SUBST_FILES.gsed=	scripts/xdg-*
SUBST_STAGE.gsed=	post-build
SUBST_MESSAGE.gsed=	Use GNU sed instead of sed.
SUBST_SED.gsed+=	-e "s/sed /gsed /g"

# "foo > /dev/null 2> /dev/null" gives "foo: not found" with NetBSD's sh
REPLACE_BASH+=	scripts/xdg-desktop-icon
REPLACE_BASH+=	scripts/xdg-desktop-menu
REPLACE_BASH+=	scripts/xdg-email
REPLACE_BASH+=	scripts/xdg-icon-resource
REPLACE_BASH+=	scripts/xdg-mime
REPLACE_BASH+=	scripts/xdg-open
REPLACE_BASH+=	scripts/xdg-screensaver
REPLACE_BASH+=	scripts/xdg-settings

.include "../../mk/bsd.pkg.mk"
