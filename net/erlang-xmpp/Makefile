# $NetBSD: Makefile,v 1.4 2017/01/21 20:17:10 fhajny Exp $

DISTNAME=	xmpp-1.1.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/xmpp/
COMMENT=	XMPP parsing and serialization library on top of Fast XML
LICENSE=	apache-2.0

DEPENDS+=	erlang-fast_xml>=1.1.19:../../textproc/erlang-fast_xml
DEPENDS+=	erlang-stringprep>=1.0.7:../../textproc/erlang-stringprep

GITHUB_PROJECT=	xmpp

BUILD_TARGET=	src

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	rebar.config
SUBST_MESSAGE.path=	Fixing include path
SUBST_VARS.path=	LOCALBASE

# Leave a non-versioned symlink in place for net/erlang-esip to find
post-install:
	${LN} -sf ${DISTNAME} ${DESTDIR}${PREFIX}/lib/erlang/lib/xmpp

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
