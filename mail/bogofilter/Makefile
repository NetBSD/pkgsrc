# $NetBSD: Makefile,v 1.21 2004/10/03 00:12:52 tv Exp $

DISTNAME=	bogofilter-0.92.6
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bogofilter/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://bogofilter.sourceforge.net/
COMMENT=	Bayesian spam filter written in C

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/bogofilter
CONF_FILES=		${EGDIR}/bogofilter.cf ${PKG_SYSCONFDIR}/bogofilter.cf

REPLACE_PERL=		src/bogoupgrade

USE_DB185=		YES

.include "../../databases/db4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
