# $NetBSD: Makefile,v 1.2 2026/10/17 23:39:36 agc Exp $

DISTNAME=		agcre-${VERSION}
PKGNAME=		libagcre-${VERSION}
VERSION=		20261015
CATEGORIES=		devel
MASTER_SITES=		-${MASTER_SITE_CODEBERG:=agc-codeberg/agcre/archive/${VERSION}.tar.gz}

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://codeberg.org/agc-codeberg/agcre/
COMMENT=		Efficient regular expression library for UTF-8 and wide chars
LICENSE=		mit

WRKSRC=			${WRKDIR}/agcre/dist

USE_LANGUAGES=		c

USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
MAKE_FILE=		Makefile.libtool
AUTO_MKDIRS=		yes

_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
