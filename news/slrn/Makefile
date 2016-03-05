# $NetBSD: Makefile,v 1.60 2016/03/05 11:29:15 jperkin Exp $

DISTNAME=	slrn-1.0.1
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=slrn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://slrn.sourceforge.net/
COMMENT=	Highly customizable threaded newsreader
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-inews --with-slrnpull --enable-spool \
			--enable-grouplens --with-libdir=${PREFIX}/lib/slrn \
			--enable-mid-cache \
			--with-slang=${BUILDLINK_PREFIX.libslang2} \
			--with-localedir=${PREFIX}/${PKGLOCALEDIR}/locale

.include "options.mk"

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/libslang2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
