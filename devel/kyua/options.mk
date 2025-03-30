# $NetBSD: options.mk,v 1.1 2025/03/30 07:52:33 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kyua
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
BUILDLINK_API_DEPENDS.atf+=	atf>=0.22
.  include "../../devel/atf/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-atf
PLIST_SUBST+=		TESTS=
post-install: post-install-tests

.PHONY: post-install-tests
post-install-tests:
	${INSTALL_DATA} ${WRKSRC}/examples/Kyuafile.top \
	    ${DESTDIR}${PREFIX}/tests/Kyuafile
TEST_TARGET=	check
.else
CONFIGURE_ARGS+=        --disable-atf
PLIST_SUBST+=           TESTS="@comment "
.endif

PRINT_PLIST_AWK+=	{ sub("^tests/", "$${TESTS}tests/"); }
