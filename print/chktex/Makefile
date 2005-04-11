# $NetBSD: Makefile,v 1.7 2005/04/11 21:47:06 tv Exp $
#

DISTNAME=	chktex-1.6.1
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://savannah.nongnu.org/download/chktex/chktex.pkg/1.6.1/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/chktex/
COMMENT=	LaTeX semantic checker

DEPENDS+=	lynx-[0-9]*:../../www/lynx

USE_GNU_TOOLS+=	make
USE_PERL5=	YES
GNU_CONFIGURE=	YES
CFLAGS+=	-D__unix__
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include "../../print/teTeX-bin/kpathsea.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
