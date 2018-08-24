# $NetBSD: Makefile,v 1.19 2018/08/24 09:35:51 wiz Exp $

DISTNAME=	Text-Diff-HTML-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Diff-HTML/
COMMENT=	HTML formatting class for Text::Diff
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-Text-Diff>=0.11:../../textproc/p5-Text-Diff
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
TEST_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Text/Diff/HTML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
