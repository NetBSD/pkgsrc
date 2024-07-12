# $NetBSD: Makefile,v 1.13 2024/07/12 18:49:04 sjmulder Exp $

DISTNAME=	mustach-1.2.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=jobol/}
GITLAB_PROJECT=	mustach
GITLAB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://gitlab.com/jobol/mustach
COMMENT=	C implementation of mustache templating
LICENSE=	0-clause-bsd

# 'test' is basic-tests and spec-tests, which downloads files with git
TEST_TARGET=	basic-tests
TEST_DEPENDS+=	valgrind-[0-9]*:../../devel/valgrind

USE_TOOLS+=	gmake gsed pkg-config

.include "../../mk/bsd.prefs.mk"

# Workaround is portable, might as well use it everywhere.
CFLAGS+=	-DNO_OPEN_MEMSTREAM

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	libs=single

.include "../../textproc/jansson/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/cJSON/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
