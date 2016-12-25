# $NetBSD: Makefile,v 1.4 2016/12/25 21:43:56 joerg Exp $

DISTNAME=	cre2
PKGNAME=	cre2-0.1b6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=marcomaggi/}
GITHUB_TAG=	0.1b6

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/re2
COMMENT=	C wrapper for re2 regular expression library
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-maintainer-mode
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	autoconf autoreconf automake gmake makeinfo
# to avoid configure: error: test for RE2 header failed
CXXFLAGS+=	-std=c++11

INFO_FILES=	yes

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} sh ./autogen.sh

.include "../../devel/re2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
