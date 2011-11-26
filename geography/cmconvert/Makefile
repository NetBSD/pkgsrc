# $NetBSD: Makefile,v 1.2 2011/11/26 04:39:55 sbd Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
