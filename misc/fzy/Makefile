# $NetBSD: Makefile,v 1.7 2026/08/04 20:29:09 wiz Exp $

DISTNAME=	fzy-1.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jhawthorn/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/jhawthorn/fzy
COMMENT=	Fuzzy text selector for the terminal
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_ENV+=	MANDIR="${PREFIX}/${PKGMANDIR}"

USE_LANGUAGES=	c99

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
