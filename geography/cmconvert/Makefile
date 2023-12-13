# $NetBSD: Makefile,v 1.5 2023/12/13 13:55:54 zafer Exp $

DISTNAME=	cmconvert-1.9.5
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	https://www.aydogan.net/distfiles/geography/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.smittyware.com/download/
COMMENT=	CacheMate import file converter for GPS GPX files

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
