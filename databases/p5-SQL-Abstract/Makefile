# $NetBSD: Makefile,v 1.6 2008/06/12 02:14:18 joerg Exp $
#

DISTNAME=	SQL-Abstract-1.21
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sqa
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SQL-Abstract/
COMMENT=	Generate SQL from Perl data structures

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/SQL/Abstract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
