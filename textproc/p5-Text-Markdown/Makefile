# $NetBSD: Makefile,v 1.1.1.1 2007/09/21 00:05:34 wiz Exp $
#

DISTNAME=	Text-Markdown-1.0.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SR/SRI/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Markdown/
COMMENT=	Convert Markdown to HTML

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Text/Markdown/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
