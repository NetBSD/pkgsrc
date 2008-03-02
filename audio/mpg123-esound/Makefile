# $NetBSD: Makefile,v 1.19 2008/03/02 06:10:33 jlam Exp $

PKGNAME=	mpg123-esound-${MPG123_VERSION}
PKGREVISION=	7
COMMENT=	Command-line player for mpeg layer 1, 2 and 3 audio with EsounD

MAINTAINER=	pkgsrc-users@NetBSD.org

PKG_DESTDIR_SUPPORT=	user-destdir

TARGET_SUFFIX=	-esd

PKG_OPTIONS_VAR=PKG_OPTIONS.mpg123-esound
.include "../../audio/mpg123/Makefile.common"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpg123 \
		${DESTDIR}${PREFIX}/bin/mpg123-esound
	${INSTALL_MAN} ${WRKSRC}/mpg123.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mpg123-esound.1

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
