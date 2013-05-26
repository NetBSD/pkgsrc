# $NetBSD: Makefile,v 1.12 2013/05/26 01:44:44 ryoon Exp $

DISTNAME=	fromcvs-rcsparse-d8303aab
# Bump simply to 0.0.0.46, I am not sure...
PKGNAME=	${RUBY_PKGPREFIX}-rcsparse-0.0.0.46
CATEGORIES=	devel ruby
MASTER_SITES=	-http://gitorious.org/fromcvs/rcsparse/archive-tarball/d8303aab
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gitorious.org/fromcvs/rcsparse
COMMENT=	RCS parsing library for Ruby
LICENSE=	corecode-license

WRKSRC=		${WRKDIR}/fromcvs-rcsparse
USE_RUBY_EXTCONF=	yes

RUBY_VERSION_SUPPORTED=	18

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
