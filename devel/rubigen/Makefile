# $NetBSD: Makefile,v 1.8 2011/03/28 14:08:38 taca Exp $

DISTNAME=	rubigen-1.5.5
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drnic.github.com/rubigen
COMMENT=	Ruby stub generator
LICENSE=	mit

RUBY_RAILS=	# defined

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

CONFLICTS+=	ruby[1-9][0-9]-rubigen-* rubigen-*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
