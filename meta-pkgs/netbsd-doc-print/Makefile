# $NetBSD: Makefile,v 1.3 2000/07/24 16:38:51 hubertf Exp $
#

DISTNAME=	netbsd-doc-print-1.0
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@netbsd.org

DEPENDS+=	jadetex>=2.20:../../print/jadetex
DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript
DEPENDS+=	netbsd-doc-1.1:../netbsd-doc

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
