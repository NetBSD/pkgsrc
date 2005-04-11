# $NetBSD: Makefile,v 1.28 2005/04/11 21:46:17 tv Exp $

DISTNAME=	bogofilter-0.92.8
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bogofilter/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://bogofilter.sourceforge.net/
COMMENT=	Bayesian spam filter written in C

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/bogofilter
CONF_FILES=		${EGDIR}/bogofilter.cf ${PKG_SYSCONFDIR}/bogofilter.cf

REPLACE_PERL=		src/bogoupgrade

BUILDLINK_TRANSFORM+=	l:db:db4

.include "../../databases/db4/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
