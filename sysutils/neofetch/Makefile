# $NetBSD: Makefile,v 1.3 2020/08/08 21:58:57 nia Exp $

DISTNAME=	neofetch-7.1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=dylanaraps/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dylanaraps/neofetch
COMMENT=	Command-line system information tool
LICENSE=	mit

USE_TOOLS+=	bash:run

USE_LANGUAGES=	# none
NO_BUILD=	yes

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

REPLACE_BASH+=	neofetch

.include "../../mk/bsd.pkg.mk"
