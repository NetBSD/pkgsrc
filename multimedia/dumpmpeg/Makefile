# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:01 tv Exp $
#

DISTNAME=	dumpmpeg-0.6
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dumpmpeg/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/dumpmpeg
COMMENT=	Splits an MPEG stream into single images

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
