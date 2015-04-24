# $NetBSD: Makefile,v 1.1 2015/04/24 18:37:07 reinoud Exp $

DISTNAME=	2.5.1
PKGNAME=	rebar-${DISTNAME}
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

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
