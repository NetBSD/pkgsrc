# $NetBSD: Makefile,v 1.4 2004/04/11 19:00:53 xtraeme Exp $
#

DISTNAME=	xanalyser-1.21
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.suse.com/pub/people/arvin/private/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.suse.de/~arvin/xanalyser/
COMMENT=	Frequency spectrum analyser for X

USE_BUILDLINK3=		yes
USE_X11=		# defined
GNU_CONFIGURE=		# defined

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
