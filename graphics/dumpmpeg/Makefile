# $NetBSD: Makefile,v 1.2 2001/06/28 22:05:27 jlam Exp $
#

DISTNAME=	dumpmpeg-0.6
CATEGORIES=	graphics
MASTER_SITES=	http://prdownloads.sourceforge.net/dumpmpeg/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/dumpmpeg
COMMENT=	Splits mpeg stream into single images

USE_BUILDLINK_ONLY=	YES
USE_CONFIG_WRAPPER=	YES
GNU_CONFIGURE=		YES

.include "../../devel/smpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
