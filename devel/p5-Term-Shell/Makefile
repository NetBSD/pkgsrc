# $NetBSD: Makefile,v 1.13 2018/08/22 09:44:42 wiz Exp $

DISTNAME=	Term-Shell-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SH/SHLOMIF/}
LICENSE=	gnu-gpl-v2

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~shlomif/${DISTNAME}/
COMMENT=	Write command-line shells in Perl

DEPENDS+=	p5-Term-ReadKey>=2.30:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Text-Autoformat-[0-9]*:../../textproc/p5-Text-Autoformat

PERL5_PACKLIST=	auto/Term/Shell/.packlist
PERL5_MODULE_TYPE= Module::Build
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
