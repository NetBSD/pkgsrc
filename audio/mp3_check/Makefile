# $NetBSD: Makefile,v 1.16 2020/03/20 11:57:22 nia Exp $
#

DISTNAME=	mp3_check-1.98
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3check/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mp3check.sourceforge.net/
COMMENT=	File checker for mp3 files

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3_check ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
