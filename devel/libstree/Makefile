# $NetBSD: Makefile,v 1.11 2013/12/10 12:01:15 jperkin Exp $
#

DISTNAME=	libstree-0.4.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.icir.org/christian/downloads/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.icir.org/christian/libstree/
COMMENT=	Suffix tree library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX:Q}/share/doc/html

CFLAGS.SunOS+=	-Du_int32_t=uint32_t

.include "../../mk/bsd.pkg.mk"
