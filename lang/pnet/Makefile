# $NetBSD: Makefile,v 1.16 2006/03/31 23:56:28 jlam Exp $

DISTNAME=	pnet-0.6.6
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.dotgnu.org/
COMMENT=	DotGNU Portable.NET (development tools)

BUILD_DEPENDS+=	treecc>=0.2.6:../../devel/treecc

CONFLICTS=	mono-[0-9]*

USE_TOOLS+=	gmake makeinfo
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INFO_FILES=	# PLIST

PTHREAD_OPTS+=	require native

CONFIGURE_ARGS+=	--enable-threads=posix

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
