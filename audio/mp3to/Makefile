# $NetBSD: Makefile,v 1.11 2008/05/25 14:45:16 tron Exp $

DISTNAME=	mp3to
PKGNAME=	${DISTNAME}-1.0.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Convert MP3 files to various other audio formats

NO_SRC_ON_FTP=	already in MASTER_SITE_LOCAL

DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123
DEPENDS+=	gmp3info>=0.8.2:../../audio/gmp3info
DEPENDS+=	sox>=12.17.1:../../audio/sox

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	YES

INSTALLATION_DIRS=	bin

do-extract:
	${MKDIR} ${WRKSRC}
	${GZCAT} ${DISTDIR}/${DISTFILES} >${WRKSRC}/${DISTFILES:S/.gz//}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3to ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
