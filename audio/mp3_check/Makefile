# $NetBSD: Makefile,v 1.7 2004/04/11 17:27:13 xtraeme Exp $
#

DISTNAME=	mp3_check-1.98
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3check/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mp3check.sourceforge.net/
COMMENT=	mp3 file checker

USE_BUILDLINK3=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3_check ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
