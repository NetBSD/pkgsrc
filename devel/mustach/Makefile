# $NetBSD: Makefile,v 1.9 2022/04/17 20:00:34 sjmulder Exp $

DISTNAME=	mustach-1.2.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/jobol/mustach/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://gitlab.com/jobol/mustach
COMMENT=	C implementation of mustache templating
LICENSE=	apache-2.0

# 'test' is basic-tests and spec-tests, which downloads files with git
TEST_TARGET=	basic-tests
TEST_DEPENDS+=	valgrind-[0-9]*:../../devel/valgrind

USE_TOOLS+=	gmake gsed pkg-config

.include "../../mk/bsd.prefs.mk"

# Workaround is portable, might as well use it everywhere.
CFLAGS+=	-DNO_OPEN_MEMSTREAM

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	libs=single

# mustach supports cjson too, add it here once in pkgsrc
.include "../../textproc/jansson/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
