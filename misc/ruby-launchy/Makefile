# $NetBSD: Makefile,v 1.9 2013/02/13 15:37:05 taca Exp $

DISTNAME=	launchy-2.2.0
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://copiousfreetime.rubyforge.org/launchy/
COMMENT=	Ruby class for launching applications
LICENSE=	isc

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3<3:../../net/ruby-addressable

USE_RAKE=	YES

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
