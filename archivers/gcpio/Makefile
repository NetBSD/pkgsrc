# $NetBSD: Makefile,v 1.8 1998/08/20 15:16:35 tsarna Exp $
#

DISTNAME=       cpio-2.4.2
PKGNAME=	gcpio-2.4.2
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/cpio/cpio.html

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-prefix=g
LDFLAGS=	-lgnumalloc

INFO_FILES=	cpio.info

.include "../../mk/bsd.pkg.mk"
