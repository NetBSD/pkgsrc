# $NetBSD: Makefile,v 1.1 2021/11/01 14:15:42 ryoon Exp $

GITHUB_PROJECT=	sfsexp
DISTNAME=	sexpr-1.3.1pre20211025
PKGNAME=	${DISTNAME:S/sexpr-/sfsexp-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjsottile/}
GITHUB_TAG=	30739f9544cfa43212769bb3b4eabfaba44b8ff6

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/mjsottile/sfsexp/
COMMENT=	Small Fast S-Expression Library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	automake

PKGCONFIG_OVERRIDE=	sfsexp.pc.in

pre-configure:
	set -e; cd ${WRKSRC}; \
	${MKDIR} m4; \
	aclocal; libtoolize; autoheader; automake -a --foreign -i; autoconf

.include "../../mk/bsd.pkg.mk"
