# $NetBSD: Makefile,v 1.30 2005/11/21 23:47:02 wiz Exp $

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

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/bogofilter
CONF_FILES=		${EGDIR}/bogofilter.cf ${PKG_SYSCONFDIR}/bogofilter.cf

USE_TOOLS+=		perl:run
REPLACE_PERL=		src/bogoupgrade

BUILDLINK_TRANSFORM+=	l:db:db4

.include "../../databases/db4/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
