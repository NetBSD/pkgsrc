# $NetBSD: Makefile,v 1.16 2005/04/03 05:06:42 mjl Exp $
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

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SQL/Statement/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
