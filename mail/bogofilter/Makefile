# $NetBSD: Makefile,v 1.6 2003/07/13 10:12:30 itojun Exp $
#

DISTNAME=	bogofilter-0.13.7.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bogofilter/}

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://bogofilter.sourceforge.net
COMMENT=	Bayesian spam filter written in C

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-db=${BUILDLINK_PREFIX.db4}/include/db4

REPLACE_PERL=	src/bogoupgrade

.include "../../databases/db4/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
