# $NetBSD: Makefile,v 1.32 2011/05/08 20:35:25 asau Exp $

DISTNAME=	gsl-1.15
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_GNU:=gsl/}

MAINTAINER=	david@maxwell.net
HOMEPAGE=	http://www.gnu.org/software/gsl/gsl.html
COMMENT=	The GNU Scientific Library
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
