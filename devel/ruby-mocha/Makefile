# $NetBSD: Makefile,v 1.4 2009/07/13 11:58:01 minskim Exp $

DISTNAME=	mocha-0.9.1
PKGNAME=	${RUBYGEM_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mocha.rubyforge.org/
COMMENT=	Ruby library for mocking and stubbing
LICENSE=	mit

.include "../../misc/rubygems/rubygem.mk"

pre-configure:
	${RM} ${WRKSRC}/Rakefile.orig

.include "../../mk/bsd.pkg.mk"
