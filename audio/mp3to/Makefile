# $NetBSD: Makefile,v 1.5 2005/06/16 06:57:39 jlam Exp $

DISTNAME=	mp3to
PKGNAME=	${DISTNAME}-1.0.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.gz

MAINTAINER=	tron@NetBSD.org
COMMENT=	Convert MP3 files to various other audio formats

NO_SRC_ON_FTP=	"already in MASTER_SITE_LOCAL"

DEPENDS+=	mpg123-[0-9]*:../mpg123
DEPENDS+=	gmp3info>=0.8.2:../gmp3info
DEPENDS+=	sox>=12.17.1:../sox

NO_BUILD=	YES

INSTALLATION_DIRS=	bin

do-extract:
	@${MKDIR} ${WRKSRC}
	@${GZCAT} ${DISTDIR}/${DISTFILES} >${WRKSRC}/${DISTFILES:S/.gz//}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3to ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
