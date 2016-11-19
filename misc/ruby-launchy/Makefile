# $NetBSD: Makefile,v 1.14 2016/11/19 14:38:03 taca Exp $

DISTNAME=	launchy-2.4.3
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/copiousfreetime/launchy
COMMENT=	Ruby class for launching applications
LICENSE=	isc

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3<3:../../net/ruby-addressable

USE_RAKE=	YES

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
