# $NetBSD: Makefile,v 1.19 2003/03/23 02:48:16 heinz Exp $
#

DISTNAME=	DBI-1.35
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dbi
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://dbi.perl.org/
COMMENT=	the database-independent Perl database access API

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
