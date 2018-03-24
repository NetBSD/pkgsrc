# $NetBSD: Makefile,v 1.5 2018/03/24 16:04:26 fhajny Exp $

DISTNAME=	eimp-1.0.3
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/eimp
COMMENT=	Erlang Image Manipulation Process
LICENSE=	apache-2.0

GITHUB_PROJECT=	eimp

DEPENDS+=	erlang-p1_utils>=1.0.10:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes

LDFLAGS.SunOS+=     -lnsl

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
