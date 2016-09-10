# $NetBSD: Makefile,v 1.7 2016/09/10 20:54:47 fhajny Exp $

DISTNAME=	rebar-2.6.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rebar/}

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://github.com/rebar/rebar/
COMMENT=	Rebar is an Erlang build tool
LICENSE=	apache-2.0

USE_TOOLS+=	gmake
AUTO_MKDIRS=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rebar ${DESTDIR}${PREFIX}/bin/rebar

SUBST_CLASSES+=		shebang
SUBST_FILES.shebang=	src/rebar_escripter.erl
SUBST_SED.shebang+=	-e 's,/usr/bin/env escript,${PREFIX}/bin/escript,'
SUBST_STAGE.shebang=	post-patch

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
