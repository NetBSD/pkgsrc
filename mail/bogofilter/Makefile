# $NetBSD: Makefile,v 1.14 2004/02/09 00:59:06 snj Exp $
#

DISTNAME=	bogofilter-0.16.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bogofilter/}

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://bogofilter.sourceforge.net/
COMMENT=	Bayesian spam filter written in C

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-libdb-prefix=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/bogofilter
CONF_FILES=		${EGDIR}/bogofilter.cf ${PKG_SYSCONFDIR}/bogofilter.cf

REPLACE_PERL=		src/bogoupgrade

BUILDLINK_TRANSFORM+=	l:db:db4

.include "../../databases/db4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
