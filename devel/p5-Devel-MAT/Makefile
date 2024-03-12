# $NetBSD: Makefile,v 1.4 2024/03/12 07:57:15 wiz Exp $

DISTNAME=	Devel-MAT-0.53
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Devel::MAT
COMMENT=	Perl Memory Analysis Tool
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Commandable-[0-9]*:../../devel/p5-Commandable
DEPENDS+=	p5-Devel-MAT-Dumper>=0.48:../../devel/p5-Devel-MAT-Dumper
DEPENDS+=	p5-Feature-Compat-Try-[0-9]*:../../devel/p5-Feature-Compat-Try
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-Heap-[0-9]*:../../devel/p5-Heap
DEPENDS+=	p5-List-UtilsBy-[0-9]*:../../devel/p5-List-UtilsBy
DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-String-Tagged-Terminal-[0-9]*:../../devel/p5-String-Tagged-Terminal
DEPENDS+=	p5-String-Tagged-[0-9]*:../../devel/p5-String-Tagged
DEPENDS+=	p5-Struct-Dumb-[0-9]*:../../devel/p5-Struct-Dumb
DEPENDS+=	p5-Syntax-Keyword-Match-[0-9]*:../../devel/p5-Syntax-Keyword-Match
TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Devel/MAT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
