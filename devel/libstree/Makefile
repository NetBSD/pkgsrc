# $NetBSD: Makefile,v 1.14 2020/03/24 17:15:47 nia Exp $

DISTNAME=	libstree-0.4.2
CATEGORIES=	devel
MASTER_SITES=	https://www.icir.org/christian/downloads/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://www.icir.org/christian/libstree/
COMMENT=	Suffix tree library
LICENSE=	mit

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CFLAGS.SunOS+=		-Du_int32_t=uint32_t

.include "../../mk/bsd.pkg.mk"
