# $NetBSD: Makefile,v 1.17 2006/09/19 19:42:48 scw Exp $
#

DISTNAME=       tits-1.2.2
CATEGORIES=	sysutils
MASTER_SITES=   http://www.mctavish.co.uk/tits/

MAINTAINER=	scw@NetBSD.org
COMMENT=	Server which provides telnet(1) access to one or more tty ports

BINDIR=		${PREFIX}/sbin
MANDIR=		${PREFIX}/man
MAKE_ENV+=	BINDIR=${BINDIR} MANDIR=${MANDIR}

MANCOMPRESSED_IF_MANZ=	yes

post-patch:
	${MV} ${WRKSRC}/tits.8 ${WRKSRC}/tits.8.in
	${SED} -e 's|/usr/local/etc|${PKG_SYSCONFDIR}|g'	\
	   -e 's|/usr/local|${PREFIX}|g'			\
	   ${WRKSRC}/tits.8.in > ${WRKSRC}/tits.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/tits.conf ${PREFIX}/share/examples/

.include "../../mk/bsd.pkg.mk"
