# $NetBSD: Makefile,v 1.1.1.1 2008/04/13 07:37:14 jlam Exp $

DISTNAME=	linecache-0.42
PKGNAME=	${RUBY_PKGPREFIX}-linecache-0.4.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rocky-hacks/linecache
COMMENT=	Ruby module to read and cache lines of a file

GEM_NAME=	linecache-${PKGVERSION_NOREV}

post-extract:
	cd ${WRKSRC} && echo ${PKGVERSION_NOREV} > VERSION

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
