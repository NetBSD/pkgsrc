# $NetBSD: Makefile,v 1.11 2003/06/02 01:21:03 jschauma Exp $
#

DISTNAME=	SQL-Statement-1.005
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sqs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	tech-pkg@netbsd.org
# HOMEPAGE=	http://
COMMENT=	small, abstract SQL engine

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SQL/Statement/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
