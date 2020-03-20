# $NetBSD: Makefile,v 1.13 2020/03/20 15:08:56 taca Exp $

DISTNAME=	rubigen-1.5.5
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drnic.github.com/rubigen
COMMENT=	Ruby stub generator
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}

CONFLICTS+=	ruby[1-9][0-9]-rubigen-* rubigen-*

RUBY_RAILS_ACCEPTED=	# defined

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
