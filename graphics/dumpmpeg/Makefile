# $NetBSD: Makefile,v 1.9 2004/04/19 04:59:01 snj Exp $
#

DISTNAME=	dumpmpeg-0.6
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dumpmpeg/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/dumpmpeg
COMMENT=	Splits mpeg stream into single images

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

.include "../../devel/smpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
