# $NetBSD: Makefile,v 1.8 2017/07/30 22:32:22 wiz Exp $

DISTNAME=	fast_xml-1.1.23
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/fast_xml/
COMMENT=	Fast Expat based Erlang XML parsing library
LICENSE=	apache-2.0

GITHUB_PROJECT=	fast_xml

DEPENDS+=	erlang-p1_utils>=1.0.9:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes

# Leave a non-versioned symlink in place for includes
post-install:
	${LN} -sf ${DISTNAME} ${DESTDIR}${PREFIX}/lib/erlang/lib/fast_xml

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
