# $NetBSD: Makefile,v 1.15 2004/12/20 11:30:57 grant Exp $
#

DISTNAME=	SQL-Statement-1.005
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sqs
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	tech-pkg@NetBSD.org
# HOMEPAGE=	http://
COMMENT=	Small, abstract SQL engine

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SQL/Statement/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
