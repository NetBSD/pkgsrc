# $NetBSD: Makefile,v 1.8 2002/07/11 19:44:29 wiz Exp $
#

DISTNAME=	netbsd-doc-print-1.1
PKGREVISION=	1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@netbsd.org
COMMENT=	meta-package including all packages to convert SGML->PDF/PS

DEPENDS+=	tex-jadetex>=2.20nb1:../../print/tex-jadetex
DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript
DEPENDS+=	netbsd-doc-1.2:../netbsd-doc

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
