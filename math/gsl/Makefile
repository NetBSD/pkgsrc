# $NetBSD: Makefile,v 1.11 2003/07/02 22:28:05 jtb Exp $

DISTNAME=		gsl-1.3
CATEGORIES=		math devel
MASTER_SITES=		${MASTER_SITE_GNU:=gsl/}

MAINTAINER=		david@maxwell.net
HOMEPAGE=		http://www.gnu.org/software/gsl/gsl.html
COMMENT=		The GNU Scientific Library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

TEST_TARGET=		check

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
