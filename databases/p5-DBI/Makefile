# $NetBSD: Makefile,v 1.20 2003/05/30 09:34:30 mjl Exp $
#

DISTNAME=	DBI-1.37
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
