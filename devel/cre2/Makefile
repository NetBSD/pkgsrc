# $NetBSD: Makefile,v 1.6 2017/05/07 03:13:24 mef Exp $

VERSION=	0.3.4
DISTNAME=	cre2-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=marcomaggi/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/re2
COMMENT=	C wrapper for re2 regular expression library
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-maintainer-mode
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	autoconf autoreconf automake gmake makeinfo

INFO_FILES=	yes

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} sh ./autogen.sh

.include "../../devel/re2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
