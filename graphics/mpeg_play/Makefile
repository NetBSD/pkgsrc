# $NetBSD: Makefile,v 1.2 1998/10/07 02:13:10 tv Exp $
# FreeBSD Id: Makefile,v 1.11 1998/10/05 03:13:32 steve Exp
#

DISTNAME=	mpeg_play-2.4
CATEGORIES=	graphics
MASTER_SITES=	ftp://mm-ftp.cs.berkeley.edu/pub/multimedia/mpeg/play/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://bmrc.berkeley.edu/projects/mpeg/mpeg_play.html

WRKSRC=		${WRKDIR}/mpeg_play
USE_IMAKE=	yes

pre-configure:
	${MV} -f ${WRKSRC}/Imakefile.proto ${WRKSRC}/Imakefile
	${MV} -f ${WRKSRC}/mpeg_play.1 ${WRKSRC}/mpeg_play.man

.include "../../mk/bsd.pkg.mk"
