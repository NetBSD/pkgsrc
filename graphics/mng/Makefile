# $NetBSD: Makefile,v 1.7 2002/10/31 08:01:21 jlam Exp $

DISTNAME=	libmng-1.0.4
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	graphics
MASTER_SITES=	http://www.3-t.com/libmng/download/ \
		${MASTER_SITE_SOURCEFORGE:=libmng/} \
		http://www.libmng.com/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.libmng.com/
COMMENT=	Multiple-image Network Graphics (MNG) reference library

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-jpeg=${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-lcms=${BUILDLINK_PREFIX.lcms}
CPPFLAGS+=		${BUILDLINK_CPPFLAGS.lcms}

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/lcms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
