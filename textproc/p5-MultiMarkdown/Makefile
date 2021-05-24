# $NetBSD: Makefile,v 1.8 2021/05/24 19:54:32 wiz Exp $

DISTNAME=	Text-MultiMarkdown-1.000035
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BO/BOBTFISH/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Text::MultiMarkdown
COMMENT=	Perl5 convert MultiMarkdown syntax to (X)HTML
LICENSE=	modified-bsd

EXTRACT_USING=	bsdtar
WRKSRC=		${WRKDIR}/${DISTNAME}

REPLACE_PERL+=	script/MultiMarkdown.pl

DEPENDS+=	p5-Module-Install-[0-9]*:../../devel/p5-Module-Install
DEPENDS+=	p5-Text-Markdown-[0-9]*:../../textproc/p5-Text-Markdown

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
