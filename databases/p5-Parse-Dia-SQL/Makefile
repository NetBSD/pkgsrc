# $NetBSD: Makefile,v 1.6 2018/08/22 09:43:20 wiz Exp $

DISTNAME=	Parse-Dia-SQL-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Parse-Dia-SQL
COMMENT=	Perl module to convert Dia diagrams to SQL
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

BUILD_DEPENDS+= p5-CPAN-Meta-[0-9]*:../../devel/p5-CPAN-Meta

DEPENDS+=	p5-Log-Log4perl-[0-9]*:../../devel/p5-Log-Log4perl
DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
DEPENDS+=	p5-Text-Table-[0-9]*:../../textproc/p5-Text-Table
DEPENDS+=	p5-XML-DOM-[0-9]*:../../textproc/p5-XML-DOM
DEPENDS+=	p5-HTML-Lint-[0-9]*:../../www/p5-HTML-Lint

PERL5_PACKLIST= auto/Parse/Dia/SQL/.packlist

REPLACE_PERL+=	bin/parsediasql

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
