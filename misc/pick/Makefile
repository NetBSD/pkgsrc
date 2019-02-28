# $NetBSD: Makefile,v 1.2 2019/02/28 19:27:43 leot Exp $

DISTNAME=	pick-3.0.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mptre/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	dbotw@gmx.net
HOMEPAGE=	https://github.com/mptre/pick/
COMMENT=	Fuzzy search tool for the command-line
LICENSE=	mit

HAS_CONFIGURE=	yes

CONFIGURE_ENV+=	INSTALL=${INSTALL_PROGRAM:Q}
CONFIGURE_ENV+=	INSTALL_MAN=${INSTALL_MAN:Q}

MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	MANDIR=${PKGMANDIR:Q}

CFLAGS.NetBSD+=	-D_OPENBSD_SOURCE	# reallocarray(3), strtonum(3)

TEST_TARGET=	test

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
