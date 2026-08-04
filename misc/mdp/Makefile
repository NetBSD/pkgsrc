# $NetBSD: Makefile,v 1.5 2026/08/04 20:29:09 wiz Exp $

DISTNAME=	mdp-1.0.15
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=visit1985/}
GITHUB_PROJECT=	mdp
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/visit1985/mdp/
COMMENT=	Command-line based markdown presentation tool
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_CURSES=	wide
FAKE_NCURSES=	yes

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
