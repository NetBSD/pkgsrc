# $NetBSD: Makefile,v 1.2 2001/02/17 18:38:21 wiz Exp $
# FreeBSD Id: Makefile,v 1.13 1998/12/01 09:49:33 asami Exp
#

DISTNAME=	pcemu1.01alpha
PKGNAME=	pcemu-1.01a
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/ \
		ftp://ftp.interface-business.de/pub/outgoing/ \
		ftp://ftp.cs.bris.ac.uk/pub/users/hedley/

MAINTAINER=	eric@fox.phoenix.az.us
COMMENT=	8086 PC emulator, by David Hedley

USE_X11=	yes
MAKE_ENV+=	FILESDIR=${FILESDIR}

post-configure:
	${SED} -e 's|/usr/local|${PREFIX}|g' < ${WRKSRC}/bootstrap/help.txt > \
		${WRKSRC}/foo
	${MV} ${WRKSRC}/foo ${WRKSRC}/bootstrap/help.txt

.include "../../mk/bsd.pkg.mk"
