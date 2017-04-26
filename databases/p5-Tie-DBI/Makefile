# $NetBSD: Makefile,v 1.11 2017/04/26 12:46:27 mef Exp $
#

DISTNAME=	Tie-DBI-1.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-DBI/
COMMENT=	Tie hashes to DBI relational databases
LICENSE=	${PERL5_LICENSE}

ALL_ENV+=	DBI_DSN=dbi:DBM:dbm_mldbm=Storable

PERL5_PACKLIST=		auto/Tie/DBI/.packlist

pre-configure:
	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f | xargs rm

# no environment may give make test PASS
do-test:
	cd ${WRKSRC} && ${MAKE} test

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
