# $NetBSD: Makefile,v 1.14 2002/08/25 21:49:04 jlam Exp $
#

DISTNAME=       cpio-2.4.2
PKGNAME=	gcpio-2.4.2
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=cpio/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/cpio/cpio.html
COMMENT=	GNU copy-in/out (cpio) with remote magnetic tape (rmt) support

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
LIBS+=		-lgnumalloc

INFO_FILES=	cpio.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
