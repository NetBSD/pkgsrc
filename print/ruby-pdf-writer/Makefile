# $NetBSD: Makefile,v 1.4 2011/08/12 17:11:08 taca Exp $

DISTNAME=	pdf-writer-1.1.8
PKGREVISION=	1
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ruby-pdf.rubyforge.org/pdf-writer/
COMMENT=	PDF generation library

DEPENDS+=	${RUBY_PKGPREFIX}-color>=1.4.0:../../graphics/ruby-color
DEPENDS+=	${RUBY_PKGPREFIX}-transaction-simple>=1.3<2:../../misc/ruby-transaction-simple

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
