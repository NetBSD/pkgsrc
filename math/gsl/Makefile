# $NetBSD: Makefile,v 1.10 2003/02/17 01:01:38 jtb Exp $

DISTNAME=		gsl-1.3
CATEGORIES=		math devel
MASTER_SITES=		${MASTER_SITE_GNU:=gsl/}

MAINTAINER=		david@maxwell.net
HOMEPAGE=		http://www.gnu.org/software/gsl/gsl.html
COMMENT=		The GNU Scientific Library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
