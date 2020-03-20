# $NetBSD: Makefile,v 1.2 2020/03/20 11:34:40 nia Exp $

DISTNAME=	neofetch-7.0.0
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
