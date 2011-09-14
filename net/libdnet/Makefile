# $NetBSD: Makefile,v 1.19 2011/09/14 17:28:19 hans Exp $
#

DISTNAME=	libdnet-1.12
PKGREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	http://libdnet.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libdnet/
COMMENT=	C interface to several low-level networking routines
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake
USE_LIBTOOL=	yes

BUILD_DEFS+=	IPV6_READY

pre-configure:
	cd ${WRKSRC} && autoconf -f

PKG_OPTIONS_VAR=	PKG_OPTIONS.libdnet
PKG_SUPPORTED_OPTIONS=	libdnetcheck
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibdnetcheck)
BUILDLINK_DEPMETHOD.check=	build
.include "../../devel/check/buildlink3.mk"
TEST_TARGET=	check
.else
CONFIGURE_ARGS+=	--without-check
.endif

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	ac_cv_dnet_linux_pf_packet=no
.endif

.include "../../mk/bsd.pkg.mk"
