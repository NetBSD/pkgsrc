# $NetBSD: Makefile,v 1.8 2004/02/04 22:23:47 abs Exp $

DISTNAME=	id3v2-0.1.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3v2/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://id3v2.sourceforge.net/
COMMENT=	Command line editor for id3v2 tags

USE_LANGUAGES=	c c++
USE_BUILDLINK2=	YES

.include "../../audio/id3lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
