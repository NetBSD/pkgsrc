# $NetBSD: Makefile,v 1.44 2024/05/29 16:33:49 adam Exp $

DISTNAME=		cclive-0.7.16
PKGREVISION=		40
CATEGORIES=		net multimedia www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cclive/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		zecrazytux@zecrazytux.net
HOMEPAGE=		http://cclive.sourceforge.net/
COMMENT=		Command line video extraction tool for user-uploaded video hosts
LICENSE=		gnu-gpl-v3

DEPENDS+=		libquvi-scripts>=0.4.0:../../net/libquvi-scripts

USE_LANGUAGES=		c c++0x
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../net/libquvi/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
