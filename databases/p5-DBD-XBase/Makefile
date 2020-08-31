# $NetBSD: Makefile,v 1.31 2020/08/31 18:06:59 wiz Exp $
#

DISTNAME=	DBD-XBase-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.fi.muni.cz/~adelton/perl/
COMMENT=	Perl DBI/DBD driver for XBase (dBase/FoxPro) databases

PERL5_PACKLIST=		auto/XBase/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
