# $NetBSD: options.mk,v 1.6 2014/06/25 13:08:37 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tor
PKG_SUPPORTED_OPTIONS=	threads doc
PKG_SUGGESTED_OPTIONS+=	doc

.if !empty(PTHREAD_TYPE:Mnative)
PKG_SUGGESTED_OPTIONS+=	threads
.endif

.include "../../mk/bsd.options.mk"

###
### This enables the build of manual pages. It requires asciidoc
### at build time, which comes with a tail of dependencies and
### may not be wanted under certain circumstances.
###
.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=		asciidoc>=8.3.3:../../textproc/asciidoc
CONFIGURE_ARGS+=	--enable-asciidoc
.else
CONFIGURE_ARGS+=	--disable-asciidoc
.endif


###
### This enables new code for threaded operation on NetBSD, OpenBSD, etc.
### I used {PTHREAD,RESOLV}_AUTO_VARS here for consistency's sake, as
### I don't trust configure scripts to do this properly on all platforms.
###
.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-threads
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
