# $NetBSD: Makefile,v 1.17 2025/11/17 11:00:19 wiz Exp $
#

DISTNAME=	mp3_check-1.98
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3check/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mp3check.sourceforge.net/
COMMENT=	File checker for mp3 files

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3_check ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
