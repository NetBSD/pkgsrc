# $NetBSD: Makefile,v 1.7 1998/06/18 16:06:37 agc Exp $
#

DISTNAME=       cpio-2.4.2
PKGNAME=	gcpio-2.4.2
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-prefix=g
LDFLAGS=	-lgnumalloc

INFO_FILES=	cpio.info

.include "../../mk/bsd.pkg.mk"
