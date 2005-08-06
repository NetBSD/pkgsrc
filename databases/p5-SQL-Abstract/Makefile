# $NetBSD: Makefile,v 1.4 2005/08/06 06:19:07 jlam Exp $
#

DISTNAME=	SQL-Abstract-1.17
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sqa
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SQL-Abstract/
COMMENT=	Generate SQL from Perl data structures

PERL5_PACKLIST=		auto/SQL/Abstract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
