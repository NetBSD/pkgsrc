# $NetBSD: Makefile,v 1.3.2.1 2002/06/23 18:46:17 jlam Exp $
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
