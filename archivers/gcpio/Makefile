# $NetBSD: Makefile,v 1.10 1999/04/14 21:39:01 tron Exp $
#

DISTNAME=       cpio-2.4.2
PKGNAME=	gcpio-2.4.2
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=cpio/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/cpio/cpio.html

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-prefix=g
LDFLAGS=	-lgnumalloc

INFO_FILES=	cpio.info

.include "../../mk/bsd.pkg.mk"
