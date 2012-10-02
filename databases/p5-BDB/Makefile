# $NetBSD: Makefile,v 1.8 2012/10/02 21:25:24 asau Exp $

DISTNAME=	BDB-1.9
PKGNAME=	p5-BDB-1.90
SVR4_PKGNAME=	p5bdb
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/BDB/
COMMENT=	Perl 5 module providing asynchronous Berkeley DB access
LICENSE=	${PERL5_LICENSE}

BDB_ACCEPTED=		db5 db4 db3 db2
PERL5_PACKLIST=		auto/BDB/.packlist

MAKE_PARAMS+=	INC=-I${BDBBASE:Q}/${BUILDLINK_INCDIRS.${BDB_TYPE}:Q}
PERL5_LDFLAGS+=	-L${BUILDLINK_PREFIX.${BDB_TYPE}} ${BDB_LIBS}

DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

.include "../../lang/perl5/module.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
