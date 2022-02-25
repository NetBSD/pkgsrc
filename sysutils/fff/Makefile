# $NetBSD: Makefile,v 1.5 2022/02/25 09:12:29 pin Exp $

DISTNAME=	fff-2.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=dylanaraps/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dylanaraps/fff/
COMMENT=	Simple file manager written in bash
LICENSE=	mit

USE_TOOLS+=	bash:run
USE_LANGUAGES=	# none
NO_BUILD=	yes

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	fff
SUBST_SED.prefix+=	-e 's,$$FFF_W3M_PATH,${PREFIX}/libexec/w3m/w3mimgdisplay,g'

REPLACE_BASH+=	fff

DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils
DEPENDS+=	xdotool-[0-9]*:../../x11/xdotool
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

.include "../../mk/bsd.pkg.mk"
