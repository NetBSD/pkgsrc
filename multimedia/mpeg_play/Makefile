# $NetBSD: Makefile,v 1.11 2021/04/25 06:41:21 wiz Exp $

DISTNAME=	mpeg_play-2.4-patched
PKGNAME=	mpeg_play-2.4patched
PKGREVISION=	2
CATEGORIES=	multimedia
#MASTER_SITES=	ftp://mm-ftp.cs.berkeley.edu/pub/multimedia/mpeg/play/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://bmrc.berkeley.edu/research/mpeg/mpeg_play.html
COMMENT=	Program to play mpeg movies on X displays

WRKSRC=		${WRKDIR}/mpeg_play
USE_IMAKE=	yes

pre-configure:
	${MV} -f ${WRKSRC}/Imakefile.proto ${WRKSRC}/Imakefile
	${MV} -f ${WRKSRC}/mpeg_play.1 ${WRKSRC}/mpeg_play.man

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
