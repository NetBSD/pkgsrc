# $NetBSD: Makefile,v 1.7 2012/10/02 21:25:34 asau Exp $

DISTNAME=	Rose-DBx-Object-MoreHelpers-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-DBx-Object-MoreHelpers/
COMMENT=	More mixin helpers for RDBO
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-Rose-DB-Object>=0.770:../../databases/p5-Rose-DB-Object
DEPENDS+=	p5-Rose-DBx-TestDB-[0-9]*:../../databases/p5-Rose-DBx-TestDB

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Rose/DBx/Object/MoreHelpers/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
