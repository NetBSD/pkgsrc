# $NetBSD: Makefile,v 1.2.2.1 2002/06/23 18:38:27 jlam Exp $
#

DISTNAME=	mp3_check-1.98
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3check/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mp3check.sourceforge.net/
COMMENT=	mp3 file checker

USE_BUILDLINK_ONLY=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3_check ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
