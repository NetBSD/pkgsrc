# $NetBSD: Makefile,v 1.7 2011/06/19 10:36:43 taca Exp $

DISTNAME=	linecache-0.46
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rocky-hacks/linecache
COMMENT=	Ruby module to read and cache lines of a file
LICENSE=	gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-rbx-require-relative>=0.0.5:../../devel/ruby-rbx-require-relative

RUBY_VERSION_SUPPORTED= 18

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
