# $NetBSD: Makefile,v 1.24 2023/07/06 09:39:24 wiz Exp $

DISTNAME=	Inline-C-0.82
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Inline/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Inline-C
COMMENT=	Write Perl Subroutines in C
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-File-ShareDir-Install-[0-9]*:../../devel/p5-File-ShareDir-Install
DEPENDS+=	p5-Inline>=0.79:../../devel/p5-Inline
DEPENDS+=	p5-Parse-RecDescent>=1.967:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-Pegex>=0.58:../../devel/p5-Pegex

# TEST_DEPENDS
TOOL_DEPENDS+=	p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive
TOOL_DEPENDS+=	p5-YAML-LibYAML-[0-9]*:../../textproc/p5-YAML-LibYAML

MAKE_ENV+=	PERL_MM_USE_DEFAULT=1

PERL5_PACKLIST=		auto/Inline/C/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
