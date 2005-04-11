# $NetBSD: Makefile,v 1.17 2005/04/11 21:45:13 tv Exp $
#

DISTNAME=	SQL-Statement-1.11
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sqs
# PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	tech-pkg@NetBSD.org
# HOMEPAGE=	http://
COMMENT=	Small, abstract SQL engine

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SQL/Statement/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
