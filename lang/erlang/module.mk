# $NetBSD: module.mk,v 1.6 2023/06/06 12:41:41 riastradh Exp $
#
# Simple Erlang module package framework
#

PKGNAME?=	erlang-${DISTNAME}

.if defined(REBAR3_BUILD)
TOOL_DEPENDS+=	rebar3-[0-9]*:../../devel/rebar3
REBAR=		${PREFIX}/bin/rebar3
.else
TOOL_DEPENDS+=	rebar-[0-9]*:../../devel/rebar
.endif

USE_TOOLS+=	gmake pax

.include "../../mk/bsd.prefs.mk"
REBAR?=		${PREFIX}/bin/rebar
MAKE_FLAGS+=	REBAR=${REBAR}

# Used by some Erlang packages to use system deps
MAKE_ENV+=	USE_GLOBAL_DEPS=true

ERL_MOD_NAME?=		${DISTNAME:C/-.*//}
ERL_MOD_DIR?=		lib/erlang/lib/${ERL_MOD_NAME}-${PKGVERSION_NOREV}
INSTALLATION_DIRS+=	${ERL_MOD_DIR}

do-install:
	cd ${WRKSRC} && ${FIND} . \( \
		-name bin -o -name ebin -o -name include -o -name priv \) \
		-exec ${PAX} -rw -pp "{}" ${DESTDIR}${PREFIX}/${ERL_MOD_DIR} ";"

.include "../../lang/erlang/buildlink3.mk"
