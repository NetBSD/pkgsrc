# $NetBSD: Makefile,v 1.19 2014/02/03 16:44:32 wiz Exp $

DISTNAME=	anki-2.0.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/anki/anki2/}
CATEGORIES=	misc x11
MASTER_SITES=	http://ankisrs.net/download/mirror/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://ankisrs.net/
COMMENT=	Flashcard learning program (v2)
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4
DEPENDS+=	lame-[0-9]*:../../audio/lame
DEPENDS+=	mplayer-[0-9]*:../../multimedia/mplayer
DEPENDS+=	portaudio-devel-[0-9]*:../../audio/portaudio-devel
# Actually, these hurt more than they help.
# anki comes with its own version of the two, and if the pkgsrc versions
# are newer, it might break
#PYTHON_VERSIONS_INCOMPATIBLE=33 # py-beautifulsoup
#DEPENDS+=	${PYPKGPREFIX}-beautifulsoup>=3.2:../../www/py-beautifulsoup
#DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
# XXX: python portaudio

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 2.0.21

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none
CONFLICTS+=		${PYPKGPREFIX}-libanki-[0-9]* ${PYPKGPREFIXP}-anki-[0-9]*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/pixmaps share/applications

REPLACE_PYTHON=		anki/anki runanki

USE_TOOLS+=	bash:run

REPLACE_BASH=		tools/tests.sh tools/build_ui.sh

SUBST_CLASSES+=		inst
SUBST_SED.inst+=	-e 's,/usr/share/anki,${PREFIX}/share/anki,'
SUBST_FILES.inst+=	anki/anki runanki
SUBST_STAGE.inst=	pre-build
SUBST_MESSAGE.inst=	Fixing installation path.

SUBST_CLASSES+=		lame
SUBST_SED.lame+=	-e 's,/usr/local,${PREFIX},'
SUBST_FILES.lame+=	anki/sound.py
SUBST_STAGE.lame=	pre-build
SUBST_MESSAGE.lame=	Fixing path to lame.

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e 's,share/man/man1,${PKGMANDIR}/man1,'
SUBST_FILES.man+=	Makefile
SUBST_STAGE.man=	pre-build
SUBST_MESSAGE.man=	Fixing path to man page directory.

MAKE_FLAGS+=		PREFIX=${PREFIX} DESTDIR=${DESTDIR}

post-extract:
	${RM} -rf ${WRKSRC}/libanki/thirdparty

# first due to patch-Makefile
# second: linux shared libraries won't help in the general case
post-install:
	rm ${DESTDIR}${PREFIX}/share/anki/Makefile.orig
	rm ${DESTDIR}${PREFIX}/share/anki/thirdparty/py*/_portaudio.so

.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
