# $NetBSD: Makefile,v 1.20 2026/11/15 17:17:13 wiz Exp $

DISTNAME=	rake-13.4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ruby/}
GITHUB_PROJECT=	rake
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/rake/
COMMENT=	Make-like build utility for Ruby
LICENSE=	mit

EXTRACT_SUFX=	.tar.gz

WRKSRC=	${WRKDIR}/${DISTNAME}

GEM_SPECFILE=	${WRKSRC}/${DISTNAME:S/-${PKGVERSION}//}.gemspec

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
