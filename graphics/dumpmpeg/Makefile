# $NetBSD: Makefile,v 1.5 2002/08/29 08:45:49 jlam Exp $
#

DISTNAME=	dumpmpeg-0.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dumpmpeg/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/dumpmpeg
COMMENT=	Splits mpeg stream into single images

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../devel/smpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
