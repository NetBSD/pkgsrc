# $NetBSD: Makefile,v 1.5 2010/08/21 16:32:58 seb Exp $
#

DISTNAME=	DBIx-Abstract-1.006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Abstract/
COMMENT=	SQL Database access functions

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/DBIx/Abstract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
