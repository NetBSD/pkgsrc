# $NetBSD: Makefile,v 1.2 2008/06/22 16:04:34 taca Exp $

DISTNAME=	linecache-0.43
PKGNAME=	${RUBY_PKGPREFIX}-linecache-0.4.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rocky-hacks/linecache
COMMENT=	Ruby module to read and cache lines of a file

GEM_NAME=	linecache-${PKGVERSION_NOREV}

post-extract:
	cd ${WRKSRC} && echo ${PKGVERSION_NOREV} > VERSION

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
