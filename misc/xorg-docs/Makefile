# $NetBSD: Makefile,v 1.11 2012/06/26 10:41:44 jperkin Exp $
#

DISTNAME=		xorg-docs-1.7
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_XORG:=doc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xorg documentation that does not fit anywhere else

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-xmlto=no
CONFIGURE_ARGS+=	--with-xsltproc=no
CONFIGURE_ARGS+=	--with-fop=no

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		MISC_MAN_SUFFIX=7
.endif

.include "../../mk/bsd.pkg.mk"
