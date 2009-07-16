# $NetBSD: Makefile,v 1.3.2.1 2009/07/16 09:20:06 tron Exp $

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
