# $NetBSD: Makefile,v 1.2 2016/01/16 18:46:30 fhajny Exp $

DISTNAME=	p1_sip-1.0.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/p1_sip/
COMMENT=	ProcessOne SIP server component
LICENSE=	gnu-gpl-v2

DEPENDS+=	erlang-p1_stun-0.9.0{nb*,}:../../net/erlang-p1_stun
DEPENDS+=	erlang-p1_tls>=1.0.0:../../security/erlang-p1_tls
DEPENDS+=	erlang-p1_utils>=1.0.2:../../misc/erlang-p1_utils

GITHUB_PROJECT=	p1_sip

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	rebar.config
SUBST_MESSAGE.path=	Fixing include path
SUBST_VARS.path=	LOCALBASE

GNU_CONFIGURE=	yes
ERL_MOD_NAME=	esip

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
