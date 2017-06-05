# $NetBSD: Makefile,v 1.21 2017/06/05 14:23:24 ryoon Exp $

DISTNAME=	OOTools-2.3
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SK/SKNPP/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/~domizio/OOTools/
COMMENT=	Perl module collection to easily create constructors methods
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Class/props/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
