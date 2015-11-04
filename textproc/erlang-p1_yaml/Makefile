# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:46 fhajny Exp $

DISTNAME=	p1_yaml-0.20151007
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/p1_yaml/
COMMENT=	Erlang wrapper for libyaml C library
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar
DEPENDS+=	erlang-p1_utils-[0-9]*:../../misc/erlang-p1_utils

GITHUB_PROJECT=	p1_yaml
GITHUB_TAG=	79f756ba73a235c4d3836ec07b5f7f2b55f49638
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

GNU_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/p1_yaml

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin priv \
		${DESTDIR}${PREFIX}/lib/erlang/lib/p1_yaml/

.include "../../lang/erlang/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
