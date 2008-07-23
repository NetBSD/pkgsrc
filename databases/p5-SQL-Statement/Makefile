# $NetBSD: Makefile,v 1.22 2008/07/23 22:57:11 rhaen Exp $
#

DISTNAME=	SQL-Statement-1.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sqs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SQL-Statement
COMMENT=	Small, abstract SQL engine

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/SQL/Statement/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
