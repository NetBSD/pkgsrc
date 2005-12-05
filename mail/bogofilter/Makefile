# $NetBSD: Makefile,v 1.32 2005/12/05 23:55:10 rillig Exp $

DISTNAME=	bogofilter-0.96.6
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bogofilter/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://bogofilter.sourceforge.net/
COMMENT=	Bayesian spam filter written in C

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/bogofilter
CONF_FILES=		${EGDIR}/bogofilter.cf ${PKG_SYSCONFDIR}/bogofilter.cf

USE_TOOLS+=		perl:run
REPLACE_PERL=		src/bogoupgrade

.include "options.mk"

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
