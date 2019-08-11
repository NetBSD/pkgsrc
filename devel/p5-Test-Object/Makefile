# $NetBSD: Makefile,v 1.17 2019/08/11 13:20:34 wiz Exp $

DISTNAME=	Test-Object-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Object
COMMENT=	Perl 5 module to thoroughly test objects

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Test/Object/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
