# $NetBSD: tool.mk,v 1.2 2023/06/06 12:41:16 riastradh Exp $

.if !defined(RUBY_PKG_CONFIG_TOOL_MK)

_PKG_CONFIG_LIBDIR?=	${BUILDLINK_DIR}/lib/pkgconfig:${BUILDLINK_DIR}/share/pkgconfig

CONFIGURE_ENV+=	PKG_CONFIG_LIBDIR=${_PKG_CONFIG_LIBDIR:Q}
CONFIGURE_ENV+=	PKG_CONFIG_PATH=
MAKE_ENV+=	PKG_CONFIG_LIBDIR=${_PKG_CONFIG_LIBDIR:Q}
MAKE_ENV+=	PKG_CONFIG_PATH=

.include "../../lang/ruby/rubyversion.mk"

TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-pkg-config-[0-9]*:../../devel/ruby-pkg-config

.endif
