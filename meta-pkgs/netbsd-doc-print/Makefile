# $NetBSD: Makefile,v 1.4 2001/02/17 17:59:19 wiz Exp $
#

DISTNAME=	netbsd-doc-print-1.0
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Meta-pkg including all pkgs to convert SGML->PDF/PS

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
