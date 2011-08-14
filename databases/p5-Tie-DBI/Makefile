# $NetBSD: Makefile,v 1.4 2011/08/14 08:18:11 obache Exp $
#

DISTNAME=	Tie-DBI-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-DBI/
COMMENT=	Tie hashes to DBI relational databases
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

ALL_ENV+=	DBI_DSN=dbi:DBM:dbm_mldbm=Storable

PERL5_PACKLIST=		auto/Tie/DBI/.packlist

pre-configure:
	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
