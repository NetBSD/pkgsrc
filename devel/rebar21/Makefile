# $NetBSD: Makefile,v 1.2 2023/01/11 22:07:46 nikita Exp $

DISTNAME=	rebar-2.6.4
PKGNAME=	${DISTNAME:S/rebar/rebar21/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rebar/}

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	https://github.com/rebar/rebar/
COMMENT=	Rebar is an Erlang build tool
LICENSE=	apache-2.0

USE_TOOLS+=	gmake
AUTO_MKDIRS=	yes

CONFLICTS+=	rebar>2 rebar3-[0-9]*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rebar ${DESTDIR}${PREFIX}/bin/rebar

SUBST_CLASSES+=		shebang
SUBST_FILES.shebang=	src/rebar_escripter.erl
SUBST_FILES.shebang+=	bootstrap
SUBST_SED.shebang+=	-e 's,/usr/bin/env escript,${PREFIX}/lib/erlang21/bin/escript,'
SUBST_STAGE.shebang=	pre-configure

.include "../../lang/erlang21/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
