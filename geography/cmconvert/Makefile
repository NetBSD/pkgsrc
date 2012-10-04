# $NetBSD: Makefile,v 1.3 2012/10/04 09:19:16 asau Exp $
#

DISTNAME=	cmconvert-1.9.5
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	http://www.smittyware.com/download/

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://www.smittyware.com/download/
COMMENT=	CacheMate import file converter for GPS GPX files

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
