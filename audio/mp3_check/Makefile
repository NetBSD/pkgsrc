# $NetBSD: Makefile,v 1.1.1.1 2001/08/02 17:50:25 drochner Exp $
#

DISTNAME=	mp3_check-1.98
CATEGORIES=	audio
MASTER_SITES=	http://prdownloads.sourceforge.net/mp3check/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mp3check.sourceforge.net/
COMMENT=	mp3 file checker

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3_check ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
