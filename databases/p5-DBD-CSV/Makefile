# $NetBSD: Makefile,v 1.23 2009/10/17 14:27:20 sno Exp $
#

DISTNAME=	DBD-CSV-0.25
PKGNAME=	p5-${DISTNAME:S/_/beta/}
SVR4_PKGNAME=	p5dcs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-CSV/
COMMENT=	Access CSV files via DBI
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-SQL-Statement>=1.22:../../databases/p5-SQL-Statement
DEPENDS+=	p5-Text-CSV_XS>=0.69:../../textproc/p5-Text-CSV_XS

PERL5_PACKLIST=	auto/DBD/CSV/.packlist

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.609
.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
