# $NetBSD: Makefile,v 1.24 2023/07/06 09:38:18 wiz Exp $

DISTNAME=	BDB-1.92
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/BDB
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
