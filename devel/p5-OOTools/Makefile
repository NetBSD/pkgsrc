# $NetBSD: Makefile,v 1.2 2004/12/20 11:31:01 grant Exp $

DISTNAME=	OOTools-1.75
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5oot
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DO/DOMIZIO/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/~domizio/OOTools/
COMMENT=	Perl module collection to easily create constructors methods

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/OOTools/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
