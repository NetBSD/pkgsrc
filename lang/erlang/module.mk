# $NetBSD: module.mk,v 1.1 2016/01/15 11:19:06 fhajny Exp $
#
# Simple Erlang module package framework
#

PKGNAME?=	erlang-${DISTNAME}

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

USE_TOOLS+=	gmake pax

REBAR?=		${PREFIX}/bin/rebar
MAKE_FLAGS+=	REBAR=${REBAR}

ERL_MOD_NAME?=		${DISTNAME:C/-.*//}
ERL_MOD_DIR?=		lib/erlang/lib/${ERL_MOD_NAME}-${PKGVERSION_NOREV}
INSTALLATION_DIRS+=	${ERL_MOD_DIR}

do-install:
	cd ${WRKSRC} && ${FIND} . \( \
		-name bin -o -name ebin -o -name include -o -name priv \) \
		-exec ${PAX} -rw -pp "{}" ${DESTDIR}${PREFIX}/${ERL_MOD_DIR} ";"

.include "../../lang/erlang/buildlink3.mk"
