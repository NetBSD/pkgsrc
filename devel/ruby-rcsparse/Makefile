# $NetBSD: Makefile,v 1.1.1.1 2007/04/21 10:35:04 wiz Exp $

DISTNAME=	rcsparse-0.0.0_20070218
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel ruby
MASTER_SITES=	#
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://ww2.fs.ei.tum.de/~corecode/hg/rcsparse/
COMMENT=	RCS parsing library for Ruby

LICENSE=	corecode-license

WRKSRC=		${WRKDIR}/rcsparse-e871e108f2e4
USE_RUBY_EXTCONF=	yes

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
