# $NetBSD: Makefile,v 1.2 2016/01/16 17:53:48 fhajny Exp $

DISTNAME=	p1_stringprep-1.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/stringprep/
COMMENT=	Erlang Stringprep native driver
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	stringprep
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
