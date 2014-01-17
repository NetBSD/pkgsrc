# $NetBSD: Makefile,v 1.12 2014/01/17 18:13:34 tsutsui Exp $

DISTNAME=	launchy-2.4.2
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/copiousfreetime/launchy
COMMENT=	Ruby class for launching applications
LICENSE=	isc

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3<3:../../net/ruby-addressable

USE_RAKE=	YES
RUBY_RDOC_REQD=	3.12

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
