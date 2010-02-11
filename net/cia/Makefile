# $NetBSD: Makefile,v 1.13 2010/02/11 20:27:45 joerg Exp $

DISTNAME=	cia-20030922
CATEGORIES=	net
MASTER_SITES=	http://scheler.de/~matthias/files/
EXTRACT_SUFX=	.tar.bz2

OWNER=		tron@NetBSD.org
COMMENT=	Simple IP accounting software

PKG_DESTDIR_SUPPORT=	user-destdir

DOC_DIR=	${PREFIX}/share/doc/cia
EXAMPLES_DIR=	${PREFIX}/share/examples/cia

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS+=	bin ${DOC_DIR} ${EXAMPLES_DIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DESTDIR}${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/ipstat/examples/*.cfg ${DESTDIR}${EXAMPLES_DIR}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
