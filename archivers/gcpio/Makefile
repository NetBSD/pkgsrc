# $NetBSD: Makefile,v 1.11 2001/02/16 13:15:27 wiz Exp $
#

DISTNAME=       cpio-2.4.2
PKGNAME=	gcpio-2.4.2
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=cpio/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/cpio/cpio.html
COMMENT=	GNU copy-in/out (cpio) with remote magnetic tape (rmt) support

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --program-prefix=g
LDFLAGS=	-lgnumalloc

INFO_FILES=	cpio.info

.include "../../mk/bsd.pkg.mk"
