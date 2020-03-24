# $NetBSD: Makefile,v 1.11 2020/03/24 18:30:19 taca Exp $

DISTNAME=	thor-1.0.1
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
