# $NetBSD: Makefile,v 1.15 2011/08/14 08:18:04 obache Exp $
#

DISTNAME=	Class-DBI-v3.0.17
PKGNAME=	p5-${DISTNAME:S:-v:-:}
PKGREVISION=	3
SVR4_PKGNAME=	p5cdi
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TM/TMTM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-DBI/
COMMENT=	Perl5 module for Simple Database Abstraction

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Accessor>=0.18:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-Trigger>=0.07:../../devel/p5-Class-Trigger
DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
DEPENDS+=	p5-File-Temp>=0.12:../../devel/p5-File-Temp
DEPENDS+=	p5-Ima-DBI>=0.33:../../databases/p5-Ima-DBI
DEPENDS+=	p5-Storable>=2.04:../../devel/p5-Storable
DEPENDS+=	p5-UNIVERSAL-moniker>=0.06:../../devel/p5-UNIVERSAL-moniker
DEPENDS+=	p5-version>=0:../../devel/p5-version

PERL5_PACKLIST=	auto/Class/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
