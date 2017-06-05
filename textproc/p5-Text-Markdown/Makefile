# $NetBSD: Makefile,v 1.21 2017/06/05 14:24:50 ryoon Exp $
#

DISTNAME=	Text-Markdown-1.000031
PKGNAME=	p5-${DISTNAME:S/000031/0.31/}
PKGREVISION=	9
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Markdown/
COMMENT=	Convert Markdown to HTML
LICENSE=	modified-bsd

BUILD_DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+= p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences

PERL5_PACKLIST=		auto/Text/Markdown/.packlist
USE_LANGUAGES=		# none

REPLACE_PERL+=	blib/script/Markdown.pl
REPLACE_PERL+=	script/Markdown.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
