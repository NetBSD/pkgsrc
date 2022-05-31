# $NetBSD: Makefile,v 1.1 2022/05/31 21:08:16 markd Exp $

DISTNAME=	Text-WordDiff-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TI/TIMK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-WordDiff
COMMENT=	Track changes between documents
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Algorithm-Diff-[0-9]*:../../devel/p5-Algorithm-Diff
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-Term-ANSIColor-[0-9]*:../../devel/p5-Term-ANSIColor

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Text/WordDiff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
