# $NetBSD: Makefile,v 1.1.1.1 2001/02/19 16:10:24 tron Exp $

DISTNAME=	mp3to
PKGNAME=	${DISTNAME}-1.0.1
CATEGORIES=	audio
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.gz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.cs.berkeley.edu/~amc/utils/
COMMENT=	Convert MP3 files to various other audio formats

DEPENDS+=	mpg123-*:../mpg123
DEPENDS+=	gmp3info>=0.8.2:../gmp3info
DEPENDS+=	sox>=12.17.1:../sox

NO_BUILD=	YES

do-extract:
	@${MKDIR} ${WRKSRC}
	@${GZCAT} ${DISTDIR}/${DISTFILES} >${WRKSRC}/${DISTFILES:S/.gz//}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3to ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
