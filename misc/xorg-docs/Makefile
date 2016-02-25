# $NetBSD: Makefile,v 1.14 2016/02/25 15:35:31 jperkin Exp $

DISTNAME=		xorg-docs-1.7.1
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_XORG:=doc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xorg documentation that does not fit anywhere else

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-xmlto=no
CONFIGURE_ARGS+=	--with-xsltproc=no
CONFIGURE_ARGS+=	--with-fop=no

CONFIGURE_ENV.SunOS+=	MISC_MAN_SUFFIX=7

.include "../../mk/bsd.pkg.mk"
