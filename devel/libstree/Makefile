# $NetBSD: Makefile,v 1.12 2016/07/24 21:29:05 rillig Exp $
#

DISTNAME=	libstree-0.4.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.icir.org/christian/downloads/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.icir.org/christian/libstree/
COMMENT=	Suffix tree library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CFLAGS.SunOS+=		-Du_int32_t=uint32_t

.include "../../mk/bsd.pkg.mk"
