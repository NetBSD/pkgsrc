# $NetBSD: Makefile,v 1.5 2003/06/02 01:21:36 jschauma Exp $
#

DISTNAME=	mp3_check-1.98
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3check/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://mp3check.sourceforge.net/
COMMENT=	mp3 file checker

USE_BUILDLINK2=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3_check ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
