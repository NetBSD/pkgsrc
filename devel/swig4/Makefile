# $NetBSD: Makefile,v 1.1 2023/02/12 10:56:55 tnn Exp $

DISTNAME=	swig-4.1.1
PKGNAME=	${DISTNAME:S/swig/swig4/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.swig.org/
COMMENT=	Simplified Wrapper and Interface Generator (version 4)
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl:build
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has sub-configure
CONFIGURE_ARGS+=	--program-suffix=4.0
CONFIGURE_ARGS+=	--with-swiglibdir=${PREFIX}/share/swig/4.0

BUILD_TARGET=	swig

.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
