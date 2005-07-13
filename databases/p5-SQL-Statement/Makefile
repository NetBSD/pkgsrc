# $NetBSD: Makefile,v 1.18 2005/07/13 18:01:21 jlam Exp $
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

PERL5_PACKLIST=		auto/SQL/Statement/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
