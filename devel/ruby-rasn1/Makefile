# $NetBSD: Makefile,v 1.1 2026/11/04 14:42:04 taca Exp $

DISTNAME=	rasn1-0.17.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/lemontree55/rasn1
COMMENT=	Ruby ASN.1 library
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-strptime>=0.2.5<0.3:../../time/ruby-strptime

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
