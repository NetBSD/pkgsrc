# $NetBSD: Makefile,v 1.110 2026/02/06 10:05:27 wiz Exp $

PKGREVISION= 3
.include "Makefile.common"

PKGNAME=	mplayer-share-${MPLAYER_VERSION}
COMMENT=	Documentation used by mplayer and gmplayer

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt # xsltproc
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=	mplayer-fonts-[0-9]*:../../fonts/mplayer-fonts

USE_TOOLS+=	gmake pax

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/mplayer/DOCS

CONFIGURE_ARGS+=	--language-doc=all
CONFIGURE_ARGS+=	--language-man=all

BUILD_TARGET=	doc

do-install:
	${INSTALL_MAN} ${WRKSRC}/DOCS/man/en/mplayer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/etc/codecs.conf ${DESTDIR}${PREFIX}/share/mplayer
	${INSTALL_DATA} ${WRKSRC}/etc/input.conf ${DESTDIR}${PREFIX}/share/mplayer
	(set -e; cd ${WRKSRC}/DOCS && \
		pax -rwppm * ${DESTDIR}${PREFIX}/share/mplayer/DOCS); \
	${FIND} ${DESTDIR}${PREFIX}/share/mplayer/DOCS -type d -print | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${PREFIX}/share/mplayer/DOCS -type f -print | \
		${XARGS} ${CHMOD} ${SHAREMODE}

# Only for configure script
BUILDLINK_DEPMETHOD.ffmpeg7=	build
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
