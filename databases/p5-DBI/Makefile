# $NetBSD: Makefile,v 1.21 2003/06/02 01:21:05 jschauma Exp $
#

DISTNAME=	DBI-1.37
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dbi
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://dbi.perl.org/
COMMENT=	the database-independent Perl database access API

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
