# $NetBSD: Makefile,v 1.34 2026/09/02 18:51:38 wiz Exp $
#
# NOTE: basically every update will require a recursive bump,
# otherwise you'll see errors like:
# /usr/lib/libpcre2-8.so.0: version PCRE2_10.47 required by /usr/lib/libglib-2.0.so.0 not defined

DISTNAME=	pcre2-10.48
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=PhilipHazel/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pcre.org/
COMMENT=	Perl Compatible Regular Expressions library (major version 2)
LICENSE=	modified-bsd

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libpcre2-16.pc.in
PKGCONFIG_OVERRIDE+=	libpcre2-posix.pc.in
PKGCONFIG_OVERRIDE+=	libpcre2-8.pc.in
PKGCONFIG_OVERRIDE+=	libpcre2-32.pc.in

CONFIGURE_ARGS+=	--enable-pcre2-16
CONFIGURE_ARGS+=	--enable-pcre2-32
CONFIGURE_ARGS+=	--enable-pcre2grep-libz
CONFIGURE_ARGS+=	--enable-pcre2grep-libbz2
# To avoid having to
# sysctl -w security.pax.mprotect.enabled=0
# because of its JIT on NetBSD.
CONFIGURE_ARGS.NetBSD+=	--enable-jit-sealloc

TEST_TARGET=		check

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
