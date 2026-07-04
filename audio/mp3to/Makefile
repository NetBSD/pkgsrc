# $NetBSD: Makefile,v 1.14 2026/07/04 06:25:03 wiz Exp $

DISTNAME=	mp3to
PKGNAME=	${DISTNAME}-1.0.1
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Convert MP3 files to various other audio formats

NO_SRC_ON_FTP=	already in MASTER_SITE_LOCAL

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123
DEPENDS+=	gmp3info>=0.8.2:../../audio/gmp3info
DEPENDS+=	sox_ng>=12.17.1:../../audio/sox_ng

REPLACE_SH=	mp3to

NO_BUILD=	YES

INSTALLATION_DIRS=	bin

do-extract:
	${MKDIR} ${WRKSRC}
	${GZCAT} ${DISTDIR}/${DISTFILES} >${WRKSRC}/${DISTFILES:S/.gz//}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3to ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
