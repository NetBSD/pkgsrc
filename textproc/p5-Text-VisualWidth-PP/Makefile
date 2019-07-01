# $NetBSD: Makefile,v 1.6 2019/07/01 21:35:54 nia Exp $

DISTNAME=	Text-VisualWidth-PP-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/T/TO/TOKUHIROM/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/T/TO/TOKUHIROM/
COMMENT=	Trimming text by the number of the columns for terminals etc
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Unicode-EastAsianWidth-[0-9]*:../../converters/p5-Unicode-EastAsianWidth

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/Text/VisualWidth/PP/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
