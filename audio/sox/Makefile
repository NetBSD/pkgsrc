# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:11 agc Exp $
# FreeBSD Id: Makefile,v 1.9 1997/02/04 10:32:34 max Exp 
#

DISTNAME=	soxgamma
PKGNAME=	sox-12.12
CATEGORIES=	audio
MASTER_SITES=	http://www.spies.com/Sox/Archive/

MAINTAINER=	torstenb@FreeBSD.ORG

NO_WRKSUBDIR=		yes
MAKEFILE=	Makefile.unx
MAN1=		sox.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sox ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/sox.man ${PREFIX}/man/man1/sox.1

.include "../../mk/bsd.pkg.mk"
