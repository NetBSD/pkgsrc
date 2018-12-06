# $NetBSD: Makefile,v 1.1 2018/12/06 14:25:06 taca Exp $

DISTNAME=	marcel-0.3.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/basecamp/marcel
COMMENT=	Simple mime type detection using magic numbers and more
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mimemagic>=0.3.2<0.4:../../misc/ruby-mimemagic

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
