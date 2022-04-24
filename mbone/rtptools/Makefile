# $NetBSD: Makefile,v 1.14 2022/04/24 12:02:13 tnn Exp $
#

DISTNAME=		rtptools-1.22
CATEGORIES=		mbone
MASTER_SITES=		${MASTER_SITE_GITHUB:=irtlab/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/irtlab/rtptools
COMMENT=		Tools for processing RTP data
LICENSE=		modified-bsd

GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf automake mandoc
CPPFLAGS+=		-Dunix
BUILD_TARGET=		all html

HTMLDIR=	${PREFIX}/share/doc/rtptools
EGDIR=		${PREFIX}/share/examples/rtptools

pre-configure:
	cd ${WRKSRC} && autoreconf -i

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/rtptools.html ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog.html ${DESTDIR}${HTMLDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/multidump ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/multiplay ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
