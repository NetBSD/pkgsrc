# $NetBSD: Makefile,v 1.13 2006/03/09 21:04:42 jlam Exp $
#

DISTNAME=	xanalyser-1.24
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.suse.com/pub/people/arvin/private/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.suse.de/~arvin/xanalyser/
COMMENT=	Frequency spectrum analyser for X

USE_LANGUAGES=		c++
GNU_CONFIGURE=		yes

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
