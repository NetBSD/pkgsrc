# $NetBSD: Makefile,v 1.1.1.1.2.1 2002/06/23 18:39:32 jlam Exp $
#

DISTNAME=	xanalyser-1.21
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.suse.com/pub/people/arvin/private/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.suse.de/~arvin/xanalyser/
COMMENT=	Frequency spectrum analyser for X

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
