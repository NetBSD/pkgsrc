# $NetBSD: Makefile,v 1.3 2001/02/27 13:43:19 wiz Exp $
#

DISTNAME=	guile-oops-0.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.gnu.org/software/guile/
COMMENT=	CLOS-like object system for Guile

DEPENDS+=	guile>=1.3.2:../../lang/guile

GNU_CONFIGURE=		YES
USE_LIBTOOL=            YES
LTCONFIG_OVERRIDE=      ${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
