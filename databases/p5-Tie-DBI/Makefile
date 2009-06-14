# $NetBSD: Makefile,v 1.1.1.1 2009/06/14 22:36:41 sno Exp $
#

DISTNAME=	Tie-DBI-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-DBI/
COMMENT=	Tie hashes to DBI relational databases 

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Encode-[0-9]*:../../textproc/p5-Encode

PERL5_PACKLIST=		auto/Tie/DBI/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
