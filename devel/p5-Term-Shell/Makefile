# $NetBSD: Makefile,v 1.8 2016/01/10 20:23:07 bsiegert Exp $

DISTNAME=	Term-Shell-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SH/SHLOMIF/}
LICENSE=	gnu-gpl-v2

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~shlomif/${DISTNAME}/
COMMENT=	Write command-line shells in Perl

DEPENDS+=	p5-Term-ReadKey>=2.30:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Text-Autoformat-[0-9]*:../../devel/p5-Term-ReadKey

PERL5_PACKLIST=	auto/Term/Shell/.packlist
PERL5_MODULE_TYPE= Module::Build
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
