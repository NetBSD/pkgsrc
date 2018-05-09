# $NetBSD: Makefile,v 1.1 2018/05/09 15:26:05 leot Exp $

DISTNAME=	pick-2.0.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mptre/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	dbotw@gmx.net
HOMEPAGE=	https://github.com/mptre/pick/
COMMENT=	Fuzzy search tool for the command-line
LICENSE=	mit

GNU_CONFIGURE=	yes

CFLAGS.NetBSD+=	-D_OPENBSD_SOURCE	# reallocarray(3), strtonum(3)

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
