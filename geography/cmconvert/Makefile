# $NetBSD: Makefile,v 1.4 2016/05/03 10:54:55 wiz Exp $

DISTNAME=	cmconvert-1.9.5
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	http://www.smittyware.com/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.smittyware.com/download/
COMMENT=	CacheMate import file converter for GPS GPX files

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
