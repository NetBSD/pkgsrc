# $NetBSD: Makefile,v 1.13 2019/06/30 20:17:02 nia Exp $

DISTNAME=	Text-Microformat-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Microformat
COMMENT=	Perl 5 Microformat parser
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Text/Microformat/.packlist
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-Class-Accessor>=0.25:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable>=0.04:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-HTML-Tree>=3.21:../../www/p5-HTML-Tree
DEPENDS+=	p5-UNIVERSAL-require>=0.10:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-XML-TreeBuilder>=3.09:../../textproc/p5-XML-TreeBuilder

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
