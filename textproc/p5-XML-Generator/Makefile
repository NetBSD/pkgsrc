# $NetBSD: Makefile,v 1.20 2023/07/06 09:42:02 wiz Exp $
#

DISTNAME=	XML-Generator-1.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Generator
COMMENT=	Perl 5 module for generating XML
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/XML/Generator/.packlist

DEPENDS+=	p5-XML-DOM-[0-9]*:../../textproc/p5-XML-DOM

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
