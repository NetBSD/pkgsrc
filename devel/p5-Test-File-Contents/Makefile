# $NetBSD: Makefile,v 1.26 2023/07/06 09:40:13 wiz Exp $

DISTNAME=	Test-File-Contents-0.242
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-File-Contents
COMMENT=	Perl5 module for test routines examining the contents of files
LICENSE=	${PERL5_LICENSE}

# for make test
TOOL_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PERL5_PACKLIST=		auto/Test/File/Contents/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
