# $NetBSD: Makefile,v 1.61 2016/06/01 13:34:23 joerg Exp $

DISTNAME=	slrn-1.0.1
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=slrn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://slrn.sourceforge.net/
COMMENT=	Highly customizable threaded newsreader
LICENSE=	gnu-gpl-v2

# gcc: error: art.o: No such file or directory
# gcc: error: art_misc.o: No such file or directory
# gcc: error: art_sort.o: No such file or directory

MAKE_JOBS_SAFE=	no

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
