
# $NetBSD: Makefile,v 1.60 2022/06/28 11:31:21 wiz Exp $

DISTNAME=	DBD-CSV-0.58
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBD-CSV
COMMENT=	Access CSV files via DBI
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-SQL-Statement>=1.412nb2:../../databases/p5-SQL-Statement
DEPENDS+=	p5-Text-CSV_XS>=1.01:../../textproc/p5-Text-CSV_XS

#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.90}:../../devel/p5-Test-Simple

CONFLICTS+=	p5-SQL-Statement<=1.27
CONFLICTS+=	p5-DBI<=1.611

PERL5_PACKLIST=	auto/DBD/CSV/.packlist
REPLACE_PERL+=	lib/DBD/CSV.pm

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.614
.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
