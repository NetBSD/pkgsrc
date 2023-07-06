# $NetBSD: Makefile,v 1.38 2023/07/06 09:41:29 wiz Exp $

DISTNAME=	psh-1.8.1
PKGNAME=	perlsh-1.8.1
PKGREVISION=	6
CATEGORIES=	shells perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GR/GREGOR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/psh
COMMENT=	The Perl Shell
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
#DEPENDS+=	{perl>=5.17.10,p5-Term-ReadLine>=1.12}:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-BSD-Resource>=1.15:../../devel/p5-BSD-Resource

PKG_SHELL=	bin/psh

PERL5_PACKLIST=	auto/psh/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
