# $NetBSD: Makefile,v 1.4 2022/06/28 11:31:30 wiz Exp $

DISTNAME=	SQL-Abstract-Classic-1.91
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SQL-Abstract-Classic
COMMENT=	Generate SQL from Perl data structures
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-SQL-Abstract-[0-9]*:../../databases/p5-SQL-Abstract
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
# should be test dependencies, but it checks it as runtime dependencies
DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PERL5_PACKLIST=		auto/SQL/Abstract/Classic/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
