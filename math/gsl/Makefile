# $NetBSD: Makefile,v 1.15 2003/09/14 14:53:06 dmcmahill Exp $

DISTNAME=		gsl-1.4
PKGREVISION=		1
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
