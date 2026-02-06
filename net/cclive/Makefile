# $NetBSD: Makefile,v 1.57 2026/02/06 10:05:29 wiz Exp $

DISTNAME=		cclive-0.7.16
PKGREVISION=		51
CATEGORIES=		net multimedia www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cclive/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		zecrazytux@zecrazytux.net
HOMEPAGE=		https://cclive.sourceforge.net/
COMMENT=		Command line video extraction tool for user-uploaded video hosts
LICENSE=		gnu-gpl-v3

DEPENDS+=		libquvi-scripts>=0.4.0:../../net/libquvi-scripts

USE_LANGUAGES=		c c++0x
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
# system was made header-only in boost 1.89
CONFIGURE_ARGS+=	boost_cv_lib_system=yes

.include "../../net/libquvi/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
