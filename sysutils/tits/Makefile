# $NetBSD: Makefile,v 1.3 2001/02/27 21:04:13 scw Exp $
#

DISTNAME=       tits-1.0.1
CATEGORIES=	sysutils
MASTER_SITES=   http://www.wee-eck.demon.co.uk/tits/

MAINTAINER=	scw@netbsd.org
COMMENT=	server which provides telnet(1) access to one or more tty ports

BINDIR=		${PREFIX}/sbin
MANDIR=		${PREFIX}/man
MAKE_ENV+=	BINDIR=${BINDIR} MANDIR=${MANDIR}

MANCOMPRESSED_IF_MANZ=	yes

post-patch:
	${MV} ${WRKSRC}/tits.8 ${WRKSRC}/tits.8.in
	${SED} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/tits.8.in > ${WRKSRC}/tits.8

post-install:
	${BSD_INSTALL_DATA} ${WRKSRC}/tits.conf ${PREFIX}/share/examples/

.include "../../mk/bsd.pkg.mk"
