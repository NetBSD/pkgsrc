# $NetBSD: Makefile,v 1.13 2020/01/26 17:31:00 rillig Exp $
#

DISTNAME=	libstree-0.4.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.icir.org/christian/downloads/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://www.icir.org/christian/libstree/
COMMENT=	Suffix tree library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CFLAGS.SunOS+=		-Du_int32_t=uint32_t

.include "../../mk/bsd.pkg.mk"
