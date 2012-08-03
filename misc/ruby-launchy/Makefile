# $NetBSD: Makefile,v 1.7 2012/08/03 10:44:56 taca Exp $

DISTNAME=	launchy-2.1.1
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://copiousfreetime.rubyforge.org/launchy/
COMMENT=	Ruby class for launching applications
LICENSE=	isc

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3<3:../../net/ruby-addressable

USE_RAKE=	YES

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
