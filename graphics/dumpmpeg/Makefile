# $NetBSD: Makefile,v 1.4 2002/05/12 10:16:47 abs Exp $
#

DISTNAME=	dumpmpeg-0.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dumpmpeg/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/dumpmpeg
COMMENT=	Splits mpeg stream into single images

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../devel/smpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
