# $NetBSD: Makefile,v 1.2 2003/04/03 12:18:18 wiz Exp $
#

DISTNAME=	bogofilter-0.11.1.3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bogofilter/}

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://bogofilter.sourceforge.net
COMMENT=	Bayesian spam filter written in C

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-db=${BUILDLINK_PREFIX.db4}/include/db4

.include "../../databases/db4/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
