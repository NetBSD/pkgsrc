# $NetBSD: Makefile,v 1.1 2019/08/31 19:55:58 schmonz Exp $

DISTNAME=	Text-MultiMarkdown-1.000035
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/B/BO/BOBTFISH/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-MultiMarkdown
COMMENT=	Convert MultiMarkdown syntax to (X)HTML
LICENSE=	modified-bsd

DEPENDS+=	p5-Digest-MD5>=0:../../security/p5-Digest-MD5
DEPENDS+=	p5-Text-Markdown>=1.0.26:../../textproc/p5-Text-Markdown

PERL5_PACKLIST=	auto/Text/MultiMarkdown/.packlist
USE_LANGUAGES=	# none

REPLACE_PERL+=	script/MultiMarkdown.pl

.include "../../textproc/p5-Encode/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
