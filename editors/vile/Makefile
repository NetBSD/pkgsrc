# $NetBSD: Makefile,v 1.9 1998/06/22 12:27:09 agc Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:55:09 gj Exp
#

DISTNAME=	vile
PKGNAME=	vile-8.0
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://id.wing.net/pub/pgf/vile/

MAINTAINER=	packages@netbsd.org

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}
INSTALL_TARGET=	install install-perl

post-install:
	@echo "You might want to copy the *.rc files from the source tree before"
	@echo "doing \`make clean'."

.include "../../mk/bsd.pkg.mk"
