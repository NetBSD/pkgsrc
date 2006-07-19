# $NetBSD: Makefile,v 1.9 2006/07/19 22:44:11 wiz Exp $
#

DISTNAME=	Text-WikiFormat-0.78
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-WikiFormat/
COMMENT=	Translate Wiki formatted text into other formats

DEPENDS+=	p5-URI>=1.30:../../www/p5-URI

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Text/WikiFormat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
