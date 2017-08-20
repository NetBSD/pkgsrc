# $NetBSD: Makefile,v 1.8 2017/08/20 12:38:02 fhajny Exp $

DISTNAME=	esip-1.0.15
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/esip/
COMMENT=	ProcessOne SIP server component in Erlang
LICENSE=	apache-2.0

DEPENDS+=	erlang-stun>=1.0.14:../../net/erlang-stun
DEPENDS+=	erlang-fast_tls>=1.0.15:../../security/erlang-fast_tls
DEPENDS+=	erlang-p1_utils>=1.0.9:../../misc/erlang-p1_utils

GITHUB_PROJECT=	esip

GNU_CONFIGURE=	yes

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	rebar.config
SUBST_MESSAGE.path=	Fixing include path
SUBST_VARS.path=	LOCALBASE

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
