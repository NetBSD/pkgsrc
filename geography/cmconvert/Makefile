# $NetBSD: Makefile,v 1.1 2008/01/23 00:54:18 rhaen Exp $
#

DISTNAME=	cmconvert-1.9.5
CATEGORIES=	geography
MASTER_SITES=	http://www.smittyware.com/download/

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://www.smittyware.com/download/
COMMENT=	CacheMate import file converter for GPS GPX files

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
