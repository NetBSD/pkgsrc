# $NetBSD: Makefile,v 1.15 2008/03/02 06:10:33 jlam Exp $
#

DISTNAME=	liveice
PKGNAME=	liveice-0.20001121
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://star.arm.ac.uk/~spm/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://star.arm.ac.uk/~spm/software/liveice.html
COMMENT=	Source client for Icecast

DEPENDS+=	mpg123-0.5*:../../audio/mpg123
DEPENDS+=	lame-3.*:../../audio/lame
DEPENDS+=	tk>=8.0:../../x11/tk

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
DIST_SUBDIR=	liveice-0.20001121
LIBS+=		${LIBOSSAUDIO}

INSTALLATION_DIRS=	bin

REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	/usr/bin/wish
REPLACE.wish.new=	${LOCALBASE}/bin/wish
REPLACE_FILES.wish=	liveiceconfigure.tk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/liveice ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/liveiceconfigure.tk ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/liveice
.for f in README.frontend README.liveice README.quickstart \
		README.xingmp3enc README_new_mixer.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/liveice
.endfor

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
