# $NetBSD: Makefile,v 1.9 2025/07/08 21:18:36 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		smtpd-starttls-proxy-0.0.2.0
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=skarnet/}
GITHUB_PROJECT=		smtpd-starttls-proxy
GITHUB_TAG=		17a5c17a1304811336129c10a3742ce33bb6aff2

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://skarnet.org/software/smtpd-starttls-proxy/
COMMENT=		STARTTLS implementation for inetd-like mail servers
LICENSE=		isc

DEPENDS+=		s6-networking>=2.7.1.0:../../net/s6-networking

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--enable-pkgconfig
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--disable-allstatic

.include "../../devel/skalibs/buildlink3.mk"
.include "../../sysutils/s6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
