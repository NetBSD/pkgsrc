# $NetBSD: Makefile,v 1.20 2019/08/11 13:20:30 wiz Exp $

DISTNAME=	Test-File-Contents-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-File-Contents
COMMENT=	Perl5 module for test routines examining the contents of files
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Test/File/Contents/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
