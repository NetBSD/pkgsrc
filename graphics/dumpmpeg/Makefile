# $NetBSD: Makefile,v 1.8 2003/07/17 21:40:19 grant Exp $
#

DISTNAME=	dumpmpeg-0.6
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dumpmpeg/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/dumpmpeg
COMMENT=	Splits mpeg stream into single images

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../devel/smpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
