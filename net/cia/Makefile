# $NetBSD: Makefile,v 1.18 2015/10/11 10:56:43 tron Exp $

DISTNAME=	cia-20030922
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://zhadum.org.uk/~tron/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple IP accounting software

DOC_DIR=	${PREFIX}/share/doc/cia
EXAMPLES_DIR=	${PREFIX}/share/examples/cia

CFLAGS.SunOS+=	-DETHERTYPE_PPPOE=ETHERTYPE_PPPOES
CFLAGS.SunOS+=	-Du_int64_t=uint64_t -Du_int32_t=uint32_t
CFLAGS.SunOS+=	-Du_int16_t=uint16_t -Du_int8_t=uint8_t

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS+=	bin ${DOC_DIR} ${EXAMPLES_DIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DESTDIR}${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/ipstat/examples/*.cfg ${DESTDIR}${EXAMPLES_DIR}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
