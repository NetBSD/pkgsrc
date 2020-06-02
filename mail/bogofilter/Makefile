# $NetBSD: Makefile,v 1.75 2020/06/02 08:24:13 adam Exp $

DISTNAME=	bogofilter-1.2.4
PKGREVISION=	17
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bogofilter/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bogofilter.sourceforge.io/
COMMENT=	Bayesian spam filter written in C
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/bogofilter

EGDIR=			${PREFIX}/share/examples/bogofilter
CONF_FILES=		${EGDIR}/bogofilter.cf.example ${PKG_SYSCONFDIR}/bogofilter.cf

USE_TOOLS+=		perl:run

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
