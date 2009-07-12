# $NetBSD: Makefile,v 1.4 2009/07/12 19:51:16 minskim Exp $

DISTNAME=	stream-0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rgl.rubyforge.org/stream/
COMMENT=	Interface for external iterators
LICENSE=	gnu-gpl-v2 # OR ruby-license

.include "../../misc/rubygems/rubygem.mk"

pre-configure:
	${RM} ${WRKSRC}/Rakefile.orig

.include "../../mk/bsd.pkg.mk"
