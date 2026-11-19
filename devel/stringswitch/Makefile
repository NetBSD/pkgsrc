# $NetBSD: Makefile,v 1.1 2026/11/19 21:48:03 agc Exp $

DISTNAME=		stringswitch-${VERSION}
VERSION=		20261119
CATEGORIES=		devel
MASTER_SITES=		-${MASTER_SITE_CODEBERG:=agc-codeberg/stringswitch/archive/${VERSION}.tar.gz}

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://codeberg.org/agc-codeberg/stringswitch/
COMMENT=		Use strings in C switch statements
LICENSE=		mit

WRKSRC=			${WRKDIR}/stringswitch/dist

USE_LANGUAGES=		c

GNU_CONFIGURE=		yes
AUTO_MKDIRS=		yes
TEST_TARGET=		t

_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
