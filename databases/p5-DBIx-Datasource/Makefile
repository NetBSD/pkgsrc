# $NetBSD: Makefile,v 1.5 2002/10/13 22:22:53 seb Exp $
#

DISTNAME=	DBIx-DataSource-0.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dxd
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.420.am/dbix-datasource
COMMENT=	create and drop functions for databases

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBIx/DataSource/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
