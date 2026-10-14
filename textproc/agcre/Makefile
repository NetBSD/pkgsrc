# $NetBSD: Makefile,v 1.2 2026/10/14 21:33:36 agc Exp $

DISTNAME=		agcre-${VERSION}
VERSION=		20261014
CATEGORIES=		textproc
MASTER_SITES=		-${MASTER_SITE_CODEBERG:=agc-codeberg/agcre/archive/${VERSION}.tar.gz}

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://codeberg.org/agc-codeberg/agcre/
COMMENT=		Efficient grep program for UTF-8 and wide chars
LICENSE=		mit

WRKSRC=			${WRKDIR}/agcre/dist

USE_LANGUAGES=		c

GNU_CONFIGURE=		yes
AUTO_MKDIRS=		yes
TEST_TARGET=		tst

_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}

.include "../../devel/libagcre/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
