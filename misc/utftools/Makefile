# $NetBSD: Makefile,v 1.7 2007/08/31 21:49:32 agc Exp $
#

DISTNAME=	utftools-1.6
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cs.yorku.ca/pub/wily/misc/

MAINTAINER=	agc@NetBSD.org
#HOMEPAGE=	none
COMMENT=	UTF-aware wc, fmt, expand, and unexpand

GNU_CONFIGURE=	yes
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../misc/libutf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
