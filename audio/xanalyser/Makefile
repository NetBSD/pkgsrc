# $NetBSD: Makefile,v 1.6 2004/10/03 00:13:10 tv Exp $
#

DISTNAME=	xanalyser-1.21
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.suse.com/pub/people/arvin/private/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.suse.de/~arvin/xanalyser/
COMMENT=	Frequency spectrum analyser for X

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c++
USE_X11=		# defined
GNU_CONFIGURE=		# defined

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
