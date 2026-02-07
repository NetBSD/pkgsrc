# $NetBSD: Makefile,v 1.22 2026/02/07 00:53:38 gdt Exp $

DISTNAME=	xmpp-1.12.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	xmpp

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/xmpp
COMMENT=	XMPP parsing and serialization library on top of Fast XML
LICENSE=	apache-2.0

# from rebar.config
DEPENDS+=	erlang-p1_utils>=1.0.26:../../misc/erlang-p1_utils
DEPENDS+=	erlang-fast_xml>=1.1.51:../../textproc/erlang-fast_xml
DEPENDS+=	erlang-fast_tls>=1.1.19:../../security/erlang-fast_tls
DEPENDS+=	erlang-ezlib>=1.0.12:../../devel/erlang-ezlib
DEPENDS+=	erlang-idna>=6.0:../../net/erlang-idna
DEPENDS+=	erlang-stringprep>=1.0.29:../../textproc/erlang-stringprep

BUILD_TARGET=	src

# Leave a non-versioned symlink in place for net/erlang-esip to find
post-install:
	${LN} -sf ${DISTNAME} ${DESTDIR}${PREFIX}/lib/erlang/lib/xmpp

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
