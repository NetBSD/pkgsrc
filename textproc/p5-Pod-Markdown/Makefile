# $NetBSD: Makefile,v 1.17 2020/11/08 04:08:09 mef Exp $

DISTNAME=	Pod-Markdown-3.300
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Pod-Markdown
COMMENT=	Convert POD to Markdown
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

TEST_DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
TEST_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PERL5_PACKLIST=		auto/Pod/Markdown/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
