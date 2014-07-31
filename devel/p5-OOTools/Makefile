# $NetBSD: Makefile,v 1.15 2014/07/31 07:45:15 hiramatsu Exp $

DISTNAME=	OOTools-2.3
PKGNAME=	p5-${DISTNAME}0
SVR4_PKGNAME=	p5oot
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SK/SKNPP/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/~domizio/OOTools/
COMMENT=	Perl module collection to easily create constructors methods
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/OOTools/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
