# $NetBSD: Makefile,v 1.10 2004/10/03 00:15:02 tv Exp $

DISTNAME=	pnet-0.6.6
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.dotgnu.org/
COMMENT=	DotGNU Portable.NET (development tools)

BUILD_DEPENDS=	treecc>=0.2.6:../../devel/treecc

CONFLICTS=	mono-[0-9]*

USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_MAKEINFO=	yes
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

INFO_FILES=	pnettools.info

PTHREAD_OPTS+=	require native

CONFIGURE_ARGS+=	--enable-threads=posix

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
