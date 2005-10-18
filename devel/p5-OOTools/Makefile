# $NetBSD: Makefile,v 1.6 2005/10/18 08:33:24 hiramatsu Exp $

DISTNAME=	OOTools-2.21
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5oot
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DO/DOMIZIO/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/~domizio/OOTools/
COMMENT=	Perl module collection to easily create constructors methods

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/OOTools/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
