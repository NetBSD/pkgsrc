# $NetBSD: Makefile,v 1.14 1999/06/26 23:04:50 agc Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:55:09 gj Exp
#

DISTNAME=	vile-8.3
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://id.wing.net/pub/pgf/vile/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-perl  --with-libdir-path=${PREFIX}/libexec
USE_PERL5=	yes
INSTALL_TARGET=	install install-perl

post-install:
	@echo "You might want to copy the *.rc files from the source tree before"
	@echo "doing \`${MAKE} clean'."

.include "../../mk/bsd.pkg.mk"
