# $NetBSD: Makefile,v 1.6 1998/06/10 08:02:08 agc Exp $
# FreeBSD Id: Makefile,v 1.9 1997/08/10 22:31:19 fenner Exp 
#

DISTNAME=       ha0999
PKGNAME=        ha-0.999b
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=   .tgz

MAINTAINER=     packages@netbsd.org

NO_WRKSUBDIR=   yes
MAKEFILE=       makefile.nix
MAKE_FLAGS=     CC=cc
ALL_TARGET=     ha
USE_GMAKE=      yes

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ha ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
