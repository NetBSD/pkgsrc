# $NetBSD: Makefile,v 1.1.1.1 2003/04/03 12:06:07 manu Exp $
#

DISTNAME=	bogofilter-0.11.1.3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bogofilter/}

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://bogofilter.sourceforge.net
COMMENT=	Bayesian spam filter written in C

DEPENDS+=	db4:../../databases/db4

HAS_CONFIGURE=	YES

CONFIGURE_ARGS+= --with-db=${BUILDLINK_PREFIX.db4}/include/db4
CONFIGURE_ARGS+= --prefix=${PREFIX}

.include "../../databases/db4/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
