# $NetBSD: Makefile,v 1.3 2015/05/03 19:44:00 joerg Exp $

DISTNAME=	2.5.1
PKGNAME=	rebar-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rebar/rebar/archive/}

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=rebar/rebar/}
COMMENT=	Rebar is an Erlang build tool
LICENSE=	apache-2.0

WRKSRC=	${WRKDIR}/rebar-2.5.1

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
