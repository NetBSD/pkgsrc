# $NetBSD: Makefile,v 1.1 2023/10/16 12:55:56 ryoon Exp $

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

.include "../../mk/bsd.pkg.mk"
