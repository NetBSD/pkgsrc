# $NetBSD: Makefile,v 1.1.1.1 2003/04/06 14:37:38 wiz Exp $
#

DISTNAME=	chktex-1.6.1
CATEGORIES=	print
MASTER_SITES=	http://savannah.nongnu.org/download/chktex/chktex.pkg/1.6.1/

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.nongnu.org/chktex/
COMMENT=	LaTeX semantic checker

DEPENDS+=	lynx-[0-9]*:../../www/lynx

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_PERL5=	YES
GNU_CONFIGURE=	YES
CFLAGS+=	-D__unix__
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include "../../print/teTeX2-bin/kpathsea.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
