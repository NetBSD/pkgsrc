# $NetBSD: Makefile,v 1.12 2019/10/12 20:14:08 rillig Exp $
#

DISTNAME=		rtptools-1.21
PKGREVISION=		1
CATEGORIES=		mbone
MASTER_SITES=		http://www.cs.columbia.edu/IRT/software/rtptools/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.columbia.edu/IRT/software/rtptools/
COMMENT=		Tools for processing RTP data
# LICENSE=		# See COPYRIGHT file, avoid direct commercial advantate

GNU_CONFIGURE=		yes
CPPFLAGS+=		-Dunix

HTMLDIR=	${PREFIX}/share/doc/rtptools
EGDIR=		${PREFIX}/share/examples/rtptools

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/rtptools.html ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog.html ${DESTDIR}${HTMLDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/multidump ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/multiplay ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
