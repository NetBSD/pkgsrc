# $NetBSD: Makefile,v 1.2 2022/12/28 13:57:22 wiz Exp $

DISTNAME=	libdevq-0.0.2
CATEGORIES=	devel

MASTER_SITES=	${MASTER_SITE_FREEBSD}
MASTER_SITES+=	http://rainbow-runner.nl/freebsd/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/freebsd/libdevq
# See also:	https://wiki.freebsd.org/Graphics
COMMENT=	Generic Device Query and Monitor interface
LICENSE=	2-clause-bsd

ONLY_FOR_PLATFORM=	DragonFly-*-* FreeBSD-*-*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	src/libdevq-1.0.pc.in

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.libdevq
PKG_SUPPORTED_OPTIONS=	diagnostic-bin
# diagnostic-bin: Build diagnostic programs

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		diagnostic-bin

.if !empty(PKG_OPTIONS:Mdiagnostic-bin)
CONFIGURE_ARGS+=		--enable-programs
PLIST.diagnostic-bin=		yes
.endif

.include "../../mk/bsd.pkg.mk"
