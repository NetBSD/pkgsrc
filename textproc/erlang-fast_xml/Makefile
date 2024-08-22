# $NetBSD: Makefile,v 1.19 2024/08/22 05:54:01 adam Exp $

DISTNAME=	fast_xml-1.1.52
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	fast_xml

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/fast_xml
COMMENT=	Fast Expat based Erlang XML parsing library
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils>=1.0.26:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes

# Leave a non-versioned symlink in place for includes
post-install:
	${LN} -sf ${DISTNAME} ${DESTDIR}${PREFIX}/lib/erlang/lib/fast_xml

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
