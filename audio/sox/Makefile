# $NetBSD: Makefile,v 1.4 1998/04/20 11:56:19 frueauf Exp $
# FreeBSD Id: Makefile,v 1.9 1997/02/04 10:32:34 max Exp 
#

DISTNAME=	soxgamma
PKGNAME=	sox-12.12
CATEGORIES=	audio
MASTER_SITES=	http://www.spies.com/Sox/Archive/

MAINTAINER=	packages@netbsd.org

NO_WRKSUBDIR=	yes
MAKEFILE=	Makefile.unx
MAN1=		sox.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sox ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/sox.man ${PREFIX}/man/man1/sox.1

.include "../../mk/bsd.pkg.mk"
