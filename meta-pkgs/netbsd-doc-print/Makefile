# $NetBSD: Makefile,v 1.18 2005/11/28 06:41:21 jlam Exp $
#

DISTNAME=	netbsd-doc-print-1.2
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Meta-package including all packages to convert SGML->PDF/PS

DEPENDS+=	tex-jadetex>=2.20nb1:../../print/tex-jadetex
DEPENDS+=	openjade-[0-9]*:../../textproc/openjade
DEPENDS+=	netbsd-doc>=1.2:../../meta-pkgs/netbsd-doc

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes
USE_TOOLS+=	gs:run

do-install:	# empty

.include "../../textproc/opensp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
