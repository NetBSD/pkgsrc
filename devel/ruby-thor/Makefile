# $NetBSD: Makefile,v 1.9 2017/09/10 13:36:01 taca Exp $

DISTNAME=	thor-0.20.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://whatisthor.com/
COMMENT=	Scripting framework that replaces rake, sake and rubigen
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-thor-[0-9]*

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
