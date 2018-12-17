# $NetBSD: Makefile,v 1.10 2018/12/17 14:57:05 taca Exp $

DISTNAME=	thor-0.20.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://whatisthor.com/
COMMENT=	Scripting framework that replaces rake, sake and rubigen
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-thor-[0-9]*

RUBYGEM_OPTIONS+=	--format-executable

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
