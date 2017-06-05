# $NetBSD: Makefile,v 1.3 2017/06/05 14:24:53 ryoon Exp $

DISTNAME=	Text-VisualWidth-PP-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/T/TO/TOKUHIROM/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/T/TO/TOKUHIROM/
COMMENT=	Trimming text by the number of the columns for terminals etc
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Text/VisualWidth/PP/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
