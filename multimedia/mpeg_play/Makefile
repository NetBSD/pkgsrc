# $NetBSD: Makefile,v 1.1.1.1 2004/02/24 21:49:22 jmmv Exp $
# FreeBSD Id: Makefile,v 1.11 1998/10/05 03:13:32 steve Exp
#

DISTNAME=	mpeg_play-2.4-patched
PKGNAME=	mpeg_play-2.4patched
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://mm-ftp.cs.berkeley.edu/pub/multimedia/mpeg/play/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://bmrc.berkeley.edu/projects/mpeg/mpeg_play.html
COMMENT=	Program to play mpeg movies on X displays

WRKSRC=		${WRKDIR}/mpeg_play
USE_IMAKE=	yes

pre-configure:
	${MV} -f ${WRKSRC}/Imakefile.proto ${WRKSRC}/Imakefile
	${MV} -f ${WRKSRC}/mpeg_play.1 ${WRKSRC}/mpeg_play.man

.include "../../mk/bsd.pkg.mk"
