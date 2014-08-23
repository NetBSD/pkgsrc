# $NetBSD: Makefile,v 1.59 2014/08/23 09:34:48 obache Exp $

DISTNAME=	slrn-1.0.1
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
