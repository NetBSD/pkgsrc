# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:22 agc Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:55:09 gj Exp
#

DISTNAME=	vile
PKGNAME=	vile-7.3
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://id.wing.net/pub/pgf/vile/

MAINTAINER=	gj@freebsd.org

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}
MAN1=		vile.1

post-install:
	@echo "You might want to copy the *.rc files from the source tree before"
	@echo "doing \`make clean'."

.include "../../mk/bsd.pkg.mk"
