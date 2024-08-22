# $NetBSD: Makefile,v 1.22 2024/08/22 05:44:35 adam Exp $

DISTNAME=	eimp-1.0.23
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	eimp

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/eimp
COMMENT=	Erlang Image Manipulation Process
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils>=1.0.25:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes

LDFLAGS.SunOS+=	-lnsl -lsocket

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
