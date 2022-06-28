# $NetBSD: Makefile,v 1.35 2022/06/28 11:31:29 wiz Exp $

DISTNAME=	Rose-DB-0.783
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Rose-DB
COMMENT=	DBI wrapper and abstraction layer
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Bit-Vector>=6.4:../../devel/p5-Bit-Vector
DEPENDS+=	p5-Clone-PP-[0-9]*:../../devel/p5-Clone-PP
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-MySQL-[0-9]*:../../time/p5-DateTime-Format-MySQL
DEPENDS+=	p5-DateTime-Format-Oracle-[0-9]*:../../time/p5-DateTime-Format-Oracle
DEPENDS+=	p5-DateTime-Format-Pg>=0.11:../../time/p5-DateTime-Format-Pg
DEPENDS+=	p5-Rose-DateTime>=0.532:../../time/p5-Rose-DateTime
DEPENDS+=	p5-Rose-Object>=0.854:../../devel/p5-Rose-Object
DEPENDS+=	p5-SQL-ReservedWords-[0-9]*:../../databases/p5-SQL-ReservedWords
DEPENDS+=	p5-Time-Clock-[0-9]*:../../time/p5-Time-Clock

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Rose/DB/.packlist

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;
	${FIND} ${WRKSRC} -name "*.pod" -type f -exec ${CHMOD} -x {} \;

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
