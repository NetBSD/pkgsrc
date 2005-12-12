# $NetBSD: Makefile,v 1.11 2005/12/12 21:36:54 joerg Exp $
#

DISTNAME=	xanalyser-1.24
PKGREVISION=	1
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
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
