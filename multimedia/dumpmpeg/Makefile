# $NetBSD: Makefile,v 1.4 2005/02/21 20:26:12 hubertf Exp $
#

DISTNAME=	dumpmpeg-0.6
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dumpmpeg/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/dumpmpeg
COMMENT=	Splits an MPEG stream into single images

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
