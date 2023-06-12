# $NetBSD: Makefile,v 1.1 2023/06/12 11:06:28 wen Exp $

DISTNAME=	Text-Transliterator-1.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Transliterator
COMMENT=	Wrapper around Perl tr/../../ operator
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Text/Transliterator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
