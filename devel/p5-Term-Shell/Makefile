# $NetBSD: Makefile,v 1.22 2022/06/28 11:33:19 wiz Exp $

DISTNAME=	Term-Shell-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SH/SHLOMIF/}
LICENSE=	gnu-gpl-v2

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SHLOMIF/${DISTNAME}
COMMENT=	Write command-line shells in Perl

DEPENDS+=	p5-Term-ReadKey>=2.30:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Text-Autoformat-[0-9]*:../../textproc/p5-Text-Autoformat

PERL5_PACKLIST=		auto/Term/Shell/.packlist
PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
