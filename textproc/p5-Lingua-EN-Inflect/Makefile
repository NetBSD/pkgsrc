# $NetBSD: Makefile,v 1.40 2023/07/06 09:41:38 wiz Exp $

DISTNAME=	Lingua-EN-Inflect-1.905
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Lingua-EN-Inflect
COMMENT=	Perl module for inflection of english words and a/an selection
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL+=	demo/demo*.pl

PERL5_PACKLIST=	auto/Lingua/EN/Inflect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
