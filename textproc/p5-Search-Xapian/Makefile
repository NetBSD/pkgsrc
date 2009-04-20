# $NetBSD: Makefile,v 1.3 2009/04/20 22:35:17 schmonz Exp $
#

DISTNAME=	Search-Xapian-1.0.12.0
PKGNAME=	${DISTNAME:S/^/p5-/}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Search/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://xapian.org/docs/bindings/perl/Search/Xapian.html
COMMENT=	Perl XS frontend to the Xapian C++ search library

USE_LANGUAGES=	c++

PERL5_PACKLIST=	auto/Search/Xapian/.packlist

.include "../../textproc/xapian/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
