# $NetBSD: Makefile,v 1.6 2003/05/02 11:55:13 wiz Exp $
#

DISTNAME=	dumpmpeg-0.6
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dumpmpeg/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/dumpmpeg
COMMENT=	Splits mpeg stream into single images

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../devel/smpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
