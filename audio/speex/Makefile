# $NetBSD: Makefile,v 1.31 2010/01/24 17:11:18 heinz Exp $
#

DISTNAME=	speex-1.2rc1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.us.xiph.org/releases/speex/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.speex.org/
COMMENT=	Open-source, patent-free voice codec
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	speex.pc.in
PKGCONFIG_OVERRIDE+=	speexdsp.pc.in
USE_TOOLS+=		pkg-config

# previous versions of the package were called Speex
CONFLICTS=	Speex-[0-9]*

CONFIGURE_ARGS+=	--with-ogg-dir=${BUILDLINK_PREFIX.libogg:Q}

BUILDLINK_TRANSFORM+=	l:gnugetopt:getopt

.include "options.mk"

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
