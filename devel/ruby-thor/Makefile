# $NetBSD: Makefile,v 1.4 2012/06/16 15:55:49 taca Exp $

DISTNAME=	thor-0.14.6
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yehudakatz.com/
COMMENT=	Scripting framework that replaces rake, sake and rubigen
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-thor-[0-9]*

# Ruby on Rails 3.2 require thor<0.15.

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
