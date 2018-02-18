# $NetBSD: Makefile,v 1.9 2018/02/18 03:35:37 rillig Exp $

DISTNAME=	String-Compare-ConstantTime-0.312
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/String-Compare-ConstantTime/
COMMENT=	Perl5 module for timing side-channel protected string compare
LICENSE=	${PERL5_LICENSE}

# EU::MM 6.31 is in core as well as Test::More 0.96 (we have 0.98)

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/String/Compare/ConstantTime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
