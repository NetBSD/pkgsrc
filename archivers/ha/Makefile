# $NetBSD: Makefile,v 1.10 2001/09/09 20:36:10 agc Exp $
# FreeBSD Id: Makefile,v 1.9 1997/08/10 22:31:19 fenner Exp 
#

DISTNAME=       ha0999
PKGNAME=        ha-0.999b
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=   .tgz

MAINTAINER=     packages@netbsd.org
COMMENT=	The HA archiver using the HSC compression method

USE_BUILDLINK_ONLY=	yes

WRKSRC=			${WRKDIR}
MAKEFILE=       makefile.nix
MAKE_FLAGS=     CC="${CC}"
ALL_TARGET=     ha
USE_GMAKE=      yes

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ha ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
