# $NetBSD: Makefile,v 1.9 2004/04/27 02:27:36 snj Exp $
#

DISTNAME=	DBIx-DataSource-0.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dxd
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.420.am/dbix-datasource
COMMENT=	Create and drop functions for databases

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBIx/DataSource/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
