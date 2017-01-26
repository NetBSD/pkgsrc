# $NetBSD: Makefile,v 1.1 2017/01/26 14:06:18 ryoon Exp $

DISTNAME=	mdp-1.0.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=visit1985/}
GITHUB_PROJECT=	mdp
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/visit1985/mdp/
COMMENT=	Command-line based markdown presentation tool
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
FAKE_NCURSES=	yes

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
