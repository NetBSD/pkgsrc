# $NetBSD: options.mk,v 1.2 2026/03/26 11:25:38 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kyua
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	tests
.if !empty(PKG_OPTIONS:Mtests)
BUILDLINK_API_DEPENDS.atf+=	atf>=0.22
.  include "../../devel/atf/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-atf
PLIST.tests=		yes
post-install: post-install-tests

.PHONY: post-install-tests
post-install-tests:
	${INSTALL_DATA} ${WRKSRC}/examples/Kyuafile.top \
	    ${DESTDIR}${PREFIX}/tests/Kyuafile
TEST_TARGET=	check
.else
CONFIGURE_ARGS+=        --disable-atf
.endif

PRINT_PLIST_AWK+=	{ sub("^tests/", "$${PLIST.tests}tests/"); }
