# $NetBSD: Makefile,v 1.15 2023/07/06 09:41:38 wiz Exp $

DISTNAME=	HTML-FormatText-WithLinks-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-FormatText-WithLinks
COMMENT=	HTML to text conversion with links as footnotes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTML-Format-[0-9]*:../../www/p5-HTML-Format

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/FormatText/WithLinks/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
