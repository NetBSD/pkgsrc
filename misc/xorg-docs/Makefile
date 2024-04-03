# $NetBSD: Makefile,v 1.17 2024/04/03 21:21:01 wiz Exp $

DISTNAME=		xorg-docs-1.7.3
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XORG:=doc/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Xorg documentation that does not fit anywhere else

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-xmlto=no
CONFIGURE_ARGS+=	--with-xsltproc=no
CONFIGURE_ARGS+=	--with-fop=no

CONFIGURE_ENV.SunOS+=	MISC_MAN_SUFFIX=7

.include "../../mk/bsd.pkg.mk"
