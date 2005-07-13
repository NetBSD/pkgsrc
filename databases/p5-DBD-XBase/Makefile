# $NetBSD: Makefile,v 1.8 2005/07/13 18:01:21 jlam Exp $
#

DISTNAME=	DBD-XBase-0.241
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xbs
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fi.muni.cz/~adelton/perl/
COMMENT=	Perl DBI/DBD driver for XBase (dBase/FoxPro) databases

PERL5_PACKLIST=	auto/XBase/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
