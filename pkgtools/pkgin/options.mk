# $NetBSD: options.mk,v 1.4 2021/10/17 10:06:28 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pkgin
PKG_SUPPORTED_OPTIONS=	pkgin-prefer-gzip

.include "../../mk/bsd.prefs.mk"

#
# Prefer pkg_summary.gz instead of .bz2 or .xz on hosts that are likely to be
# slower or have limited memory where the higher compression can cause issues.
#
PROBABLY_SLOW_ARCHS=	alpha hppa i386 m68k powerpc sh3eb sh3el sparc vax
.if !empty(PROBABLY_SLOW_ARCHS:M${MACHINE_ARCH})
PKG_SUGGESTED_OPTIONS=	pkgin-prefer-gzip
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpkgin-prefer-gzip)
CPPFLAGS+=	-DPREFER_GZIP_SUMMARY
.endif
