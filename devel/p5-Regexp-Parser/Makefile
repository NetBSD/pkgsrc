# $NetBSD: Makefile,v 1.20 2022/06/28 11:33:09 wiz Exp $

DISTNAME=	Regexp-Parser-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Regexp-Parser
COMMENT=	Perl 5 base class for parsing regexes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Regexp/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
