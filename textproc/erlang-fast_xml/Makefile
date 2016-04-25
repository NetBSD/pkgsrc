# $NetBSD: Makefile,v 1.1 2016/04/25 14:33:38 fhajny Exp $

DISTNAME=	fast_xml-1.1.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/fast_xml/
COMMENT=	Fast Expat based Erlang XML parsing library
LICENSE=	apache-2.0

GITHUB_PROJECT=	fast_xml

DEPENDS+=	erlang-p1_utils>=1.0.3:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
