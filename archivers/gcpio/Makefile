# $NetBSD: Makefile,v 1.13 2002/02/18 15:14:00 seb Exp $
#

DISTNAME=       cpio-2.4.2
PKGNAME=	gcpio-2.4.2
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU:=cpio/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/cpio/cpio.html
COMMENT=	GNU copy-in/out (cpio) with remote magnetic tape (rmt) support

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
LIBS+=			-lgnumalloc

INFO_FILES=	cpio.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
