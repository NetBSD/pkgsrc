# $NetBSD: Makefile,v 1.2 2026/08/04 20:28:52 wiz Exp $

DISTNAME=	pystring-1.1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=imageworks/}
GITHUB_PROJECT=	pystring
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/imageworks/pystring/
COMMENT=	Pythons string methods for C++ std::string
LICENSE=	mit

USE_LIBTOOL=	yes
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	include/pystring lib

post-install:
	${RUN} ${INSTALL_DATA} ${WRKSRC}/pystring.h \
		${DESTDIR}${PREFIX}/include/pystring

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
