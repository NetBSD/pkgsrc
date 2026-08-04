# $NetBSD: Makefile,v 1.30 2026/08/04 20:28:58 wiz Exp $
#

DISTNAME=	xrick-021212
PKGREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://www.bigorno.net/xrick/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pino@dohd.org
HOMEPAGE=	http://www.bigorno.net/xrick/
COMMENT=	Rick Dangerous clone for X

RESTRICTED=		Copyright of graphics, images, maps, and sounds is questionable.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

USE_TOOLS+=		gmake gunzip

SUBST_CLASSES+=		data
SUBST_STAGE.data=	pre-configure
SUBST_MESSAGE.data=	Adjusting path to data.zip
SUBST_FILES.data=	src/xrick.c
SUBST_SED.data=		-e "s|data.zip|${PREFIX}/share/xrick/&|"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

post-extract:
	cd ${WRKSRC} && ${GUNZIP_CMD} xrick.6.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrick ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xrick.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/xrick
	${INSTALL_DATA} ${WRKSRC}/data.zip ${DESTDIR}${PREFIX}/share/xrick

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
