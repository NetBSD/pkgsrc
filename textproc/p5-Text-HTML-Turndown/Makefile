# $NetBSD: Makefile,v 1.2 2025/03/30 16:05:29 schmonz Exp $

DISTNAME=	Text-HTML-Turndown-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CO/CORION/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/Corion/Text-HTML-Turndown
COMMENT=	Convert HTML to Markdown
LICENSE=	artistic-2.0

PERL5_PACKLIST=	auto/Text/HTML/Turndown/.packlist
USE_LANGUAGES=	# none

DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moo>=2:../../devel/p5-Moo
DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML

#TEST_DEPENDS+=	p5-JSON-Tiny-[0-9]*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
