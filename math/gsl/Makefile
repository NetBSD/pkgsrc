# $NetBSD: Makefile,v 1.13 2003/08/09 11:11:31 seb Exp $

DISTNAME=		gsl-1.3
CATEGORIES=		math devel
MASTER_SITES=		${MASTER_SITE_GNU:=gsl/}

MAINTAINER=		david@maxwell.net
HOMEPAGE=		http://www.gnu.org/software/gsl/gsl.html
COMMENT=		The GNU Scientific Library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
INFO_FILES=		gsl-ref.info

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
