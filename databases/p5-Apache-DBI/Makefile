# $NetBSD: Makefile,v 1.4 2003/07/17 21:28:29 grant Exp $
#

DISTNAME=	ApacheDBI-0.88
PKGNAME=	p5-Apache-DBI-0.88
SVR4_PKGNAME=	p5adb
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.symbolstone.org/technology/perl/DBI/index.html
COMMENT=	DBI support for Apache+mod_perl

DEPENDS+=		p5-DBI>=1.13:../../databases/p5-DBI

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
