# $NetBSD: Makefile,v 1.5 2004/03/11 08:06:56 jlam Exp $

DISTNAME=	pnet-0.6.2
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.dotgnu.org/
COMMENT=	DotGNU Portable.NET (development tools)

BUILD_DEPENDS=	treecc>=0.2.6:../../devel/treecc

CONFLICTS=	mono-[0-9]*

USE_GNU_TOOLS+=	make
USE_MAKEINFO=	yes
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

INFO_FILES=	pnettools.info

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
