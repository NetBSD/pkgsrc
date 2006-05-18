# $NetBSD: Makefile,v 1.14 2006/05/18 15:45:09 gavan Exp $
#

DISTNAME=       tits-1.1.1
CATEGORIES=	sysutils
MASTER_SITES=   http://www.mctavish.co.uk/tits/

MAINTAINER=	scw@NetBSD.org
COMMENT=	Server which provides telnet(1) access to one or more tty ports

BINDIR=		${PREFIX}/sbin
MANDIR=		${PREFIX}/man
MAKE_ENV+=	BINDIR=${BINDIR:Q} MANDIR=${MANDIR:Q}
RCD_SCRIPTS=	tits

MANCOMPRESSED_IF_MANZ=	yes

post-patch:
	${MV} ${WRKSRC}/tits.8 ${WRKSRC}/tits.8.in
	${SED} -e 's|/usr/local/etc|${PKG_SYSCONFDIR}|g'	\
	   -e 's|/usr/local|${PREFIX}|g'			\
	   ${WRKSRC}/tits.8.in > ${WRKSRC}/tits.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/tits.conf ${PREFIX}/share/examples/

.include "../../mk/bsd.pkg.mk"
