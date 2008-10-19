# $NetBSD: Makefile,v 1.2 2008/10/19 19:17:46 he Exp $

DISTNAME=	Search-QueryParser-SQL-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Search/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Search-QueryParser-SQL/
COMMENT=	Perl module to turn free-text queries into SQL WHERE clauses

DEPENDS+=	p5-Search-QueryParser>=0.93:../../databases/p5-Search-QueryParser/
DEPENDS+=	p5-Data-Dump>=0:../../devel/p5-Data-Dump

PERL5_PACKLIST=	auto/Search/QueryParser/SQL/.packlist

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
