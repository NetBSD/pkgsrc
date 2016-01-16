# $NetBSD: Makefile,v 1.2 2016/01/16 18:42:25 fhajny Exp $

DISTNAME=	p1_stun-0.9.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/stun/
COMMENT=	STUN for ejabberd
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_tls>=1.0.0:../../security/erlang-p1_tls
DEPENDS+=	erlang-p1_utils>=1.0.2:../../misc/erlang-p1_utils

GITHUB_PROJECT=	stun
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

BUILD_TARGET=	src

# Leave a non-versioned symlink in place for net/erlang-p1_sip to find
post-install:
	${LN} -sf ${DISTNAME} ${DESTDIR}${PREFIX}/lib/erlang/lib/p1_stun

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
