# $NetBSD: Makefile,v 1.12 2004/01/14 20:16:39 manu Exp $
#

DISTNAME=	bogofilter-0.15.7nb1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bogofilter/}

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://bogofilter.sourceforge.net/
COMMENT=	Bayesian spam filter written in C

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-db=${BUILDLINK_PREFIX.db4}/include/db4
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/bogofilter
CONF_FILES=		${EGDIR}/bogofilter.cf ${PKG_SYSCONFDIR}/bogofilter.cf

REPLACE_PERL=		src/bogoupgrade

.include "../../databases/db4/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
