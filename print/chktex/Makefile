# $NetBSD: Makefile,v 1.12 2005/10/22 13:07:24 wiz Exp $
#

DISTNAME=	chktex-1.6.1
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://savannah.nongnu.org/download/chktex/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/chktex/
COMMENT=	LaTeX semantic checker

DEPENDS+=	lynx-[0-9]*:../../www/lynx

USE_TOOLS+=	gmake perl:run
GNU_CONFIGURE=	YES
CFLAGS+=	-D__unix__
CONFIGURE_ENV+=	PERL5="${PERL5}"
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include "../../print/teTeX-bin/kpathsea.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
