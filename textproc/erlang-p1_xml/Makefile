# $NetBSD: Makefile,v 1.3 2016/01/16 18:56:51 fhajny Exp $

DISTNAME=	p1_xml-1.1.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/xml/
COMMENT=	Fast Expat based Erlang XML parsing library
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils>=1.0.0:../../misc/erlang-p1_utils

GITHUB_PROJECT=	xml
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

GNU_CONFIGURE=	yes

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
