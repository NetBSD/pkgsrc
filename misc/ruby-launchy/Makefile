# $NetBSD: Makefile,v 1.16 2020/03/23 16:49:31 taca Exp $

DISTNAME=	launchy-2.5.0
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/copiousfreetime/launchy
COMMENT=	Ruby class for launching applications
LICENSE=	isc

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3<3:../../net/ruby-addressable

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
