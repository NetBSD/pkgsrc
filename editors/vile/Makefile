# $NetBSD: Makefile,v 1.7 1998/05/06 07:56:35 agc Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:55:09 gj Exp
#

DISTNAME=	vile
PKGNAME=	vile-7.3
CATEGORIES=	editors
# agc - vile-7.4 is on the MASTER_SITES now, so grab the 7.3 distfile
#	from ftp.netbsd.org. We'll do a 7.4 package ASAP, when circumstances
#	permit.
# MASTER_SITES=   ftp://ftp.clark.net/pub/dickey/vile/ \
#		ftp://id.wing.net/pub/pgf/vile/
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/

MAINTAINER=	packages@netbsd.org

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}
MAN1=		vile.1

post-install:
	@echo "You might want to copy the *.rc files from the source tree before"
	@echo "doing \`make clean'."

.include "../../mk/bsd.pkg.mk"
