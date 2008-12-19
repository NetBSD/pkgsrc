# $NetBSD: Makefile,v 1.29 2008/12/19 23:16:22 tnn Exp $

DISTNAME=	gsl-1.12
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_GNU:=gsl/}

MAINTAINER=	david@maxwell.net
HOMEPAGE=	http://www.gnu.org/software/gsl/gsl.html
COMMENT=	The GNU Scientific Library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
