# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:50 agc Exp $
# FreeBSD Id: Makefile,v 1.12 1997/07/17 19:29:07 andreas Exp
#

DISTNAME=       glimpse-4.0.src
PKGNAME=	glimpse-4.0
CATEGORIES=	textproc databases
MASTER_SITES=   ftp://ftp.cs.arizona.edu/glimpse/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	chuckr@freebsd.org

NO_CDROM=	"Restrictive copyright (don't sell for profit)"
GNU_CONFIGURE=	yes
MAN1=		glimpse.1 glimpseindex.1 glimpseserver.1 agrep.1

pre-configure:
	chmod ugo+x ${WRKSRC}/configure

post-install:
	${MKDIR} ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/glimpse
	${INSTALL_PROGRAM} ${WRKSRC}/index/wgconvert ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
