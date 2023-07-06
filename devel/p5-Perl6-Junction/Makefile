# $NetBSD: Makefile,v 1.22 2023/07/06 09:39:53 wiz Exp $

DISTNAME=	Perl6-Junction-1.60000
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Perl6/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Perl6::Junction
COMMENT=	Perl6 style Junction operators in Perl5
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Perl6/Junction/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
