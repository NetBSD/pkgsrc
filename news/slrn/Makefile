# $NetBSD: Makefile,v 1.67 2020/04/13 12:00:48 nia Exp $

DISTNAME=	slrn-1.0.3a
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://jedsoft.org/releases/slrn/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://slrn.sourceforge.net/
COMMENT=	Highly customizable threaded newsreader
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/slrn-1.0.3

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-inews
CONFIGURE_ARGS+=	--enable-spool
CONFIGURE_ARGS+=	--enable-grouplens
CONFIGURE_ARGS+=	--enable-mid-cache
CONFIGURE_ARGS+=	--with-slrnpull
CONFIGURE_ARGS+=	--with-libdir=${PREFIX}/lib/slrn
CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_PREFIX.libslang2}
CONFIGURE_ARGS+=	--with-localedir=${PREFIX}/${PKGLOCALEDIR}/locale

.include "options.mk"

LDFLAGS.SunOS+=	-lsocket -lnsl

BUILDLINK_API_DEPENDS.libslang2+=	libslang2>=2.2.3
.include "../../devel/libslang2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
