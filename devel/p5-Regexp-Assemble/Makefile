# $NetBSD: Makefile,v 1.23 2022/06/28 11:33:09 wiz Exp $

DISTNAME=	Regexp-Assemble-0.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Regexp-Assemble
COMMENT=	Perl 5 module to assemble multiple regular expressions
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Regexp/Assemble/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
