# $NetBSD: Makefile,v 1.13 2004/02/22 20:48:16 jmmv Exp $
#

DISTNAME=	netbsd-doc-print-1.1
PKGREVISION=	1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	Meta-package including all packages to convert SGML->PDF/PS

DEPENDS+=	tex-jadetex>=2.20nb1:../../print/tex-jadetex
DEPENDS+=	netbsd-doc-1.2:../netbsd-doc

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
