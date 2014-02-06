# $NetBSD: Makefile,v 1.18 2014/02/06 13:05:04 abs Exp $

DISTNAME=	Rose-DB-Object-0.810
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jsiracusa/Rose-DB-Object/
COMMENT=	Extensible, high performance RDBMS-OO mapper
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Bit-Vector>=6.4:../../devel/p5-Bit-Vector
DEPENDS+=	p5-Clone>=0.29:../../devel/p5-Clone
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Rose-DB>=0.763:../../databases/p5-Rose-DB
DEPENDS+=	p5-Rose-DateTime>=0.532:../../time/p5-Rose-DateTime
DEPENDS+=	p5-Rose-Object>=0.854:../../devel/p5-Rose-Object
DEPENDS+=	p5-Time-Clock-[0-9]*:../../time/p5-Time-Clock

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Rose/DB/Object/.packlist

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;
	${FIND} ${WRKSRC} -name "*.pod" -type f -exec ${CHMOD} -x {} \;

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
