# $NetBSD: Makefile,v 1.1.1.1 2002/04/30 12:33:29 wiz Exp $
#

DISTNAME=	binutils-2.11.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}

PATCHFILES=	binutils-NetBSD-diff-20020418.patch.bz2
PATCH_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/directory/binutils.html
COMMENT=	GNU binary utilities

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

.include "../../mk/bsd.pkg.mk"
