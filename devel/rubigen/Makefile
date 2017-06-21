# $NetBSD: Makefile,v 1.10 2017/06/21 15:42:10 taca Exp $

DISTNAME=	rubigen-1.5.5
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drnic.github.com/rubigen
COMMENT=	Ruby stub generator
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

CONFLICTS+=	ruby[1-9][0-9]-rubigen-* rubigen-*

RUBY_RAILS_SUPPORTED=	# defined

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
