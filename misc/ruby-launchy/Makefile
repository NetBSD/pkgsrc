# $NetBSD: Makefile,v 1.11 2013/09/15 14:10:09 taca Exp $

DISTNAME=	launchy-2.3.0
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://copiousfreetime.rubyforge.org/launchy/
COMMENT=	Ruby class for launching applications
LICENSE=	isc

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.3<3:../../net/ruby-addressable

USE_RAKE=	YES
RUBY_RDOC_REQD=	3.12

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
