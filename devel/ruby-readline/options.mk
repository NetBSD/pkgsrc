# $NetBSD: options.mk,v 1.5 2013/07/15 02:02:21 ryoon Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.ruby
PKG_SUPPORTED_OPTIONS=	readline ruby-build-ri-db

#
# GNU readline supports multi bytes characters.
#
PKG_SUGGESTED_OPTIONS=	ruby-build-ri-db

.include "../../lang/ruby/rubyversion.mk"

# Since license of Ruby prior to 1.9.3 is incompatible with newer
# readline's GPL3, enable it with 1.9.3 and lator.
#
.if ${RUBY_VER} != 18 && ${RUBY_VER} != 19
PKG_SUGGESTED_OPTIONS+=	readline
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mreadline)
CONFIGURE_ARGS+=	--enable-libedit
.  include "../../mk/readline.buildlink3.mk"
.endif
