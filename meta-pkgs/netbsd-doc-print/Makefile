# $NetBSD: Makefile,v 1.16 2005/07/12 16:57:36 hubertf Exp $
#

DISTNAME=	netbsd-doc-print-1.2
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Meta-package including all packages to convert SGML->PDF/PS

DEPENDS+=	tex-jadetex>=2.20nb1:../../print/tex-jadetex
DEPENDS+=	openjade-[0-9]*:../../textproc/openjade
DEPENDS+=	netbsd-doc>=1.2:../netbsd-doc

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../textproc/opensp/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
