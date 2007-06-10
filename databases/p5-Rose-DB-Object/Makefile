# $NetBSD: Makefile,v 1.1.1.1 2007/06/10 13:48:23 abs Exp $

DISTNAME=	Rose-DB-Object-0.764
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/~jsiracusa/Rose-DB-Object/
COMMENT=	Extensible, high performance RDBMS-OO mapper

DEPENDS+=	p5-Bit-Vector>=6.4:../../devel/p5-Bit-Vector
DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
DEPENDS+=	p5-DBI>=1.4:../../databases/p5-DBI
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Rose-DB>=0.734:../../databases/p5-Rose-DB
DEPENDS+=	p5-Rose-DateTime-[0-9]*:../../time/p5-Rose-DateTime

PERL5_PACKLIST=         auto/Rose/DB/Object/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
