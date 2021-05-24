# $NetBSD: Makefile,v 1.22 2021/05/24 19:49:43 wiz Exp $

DISTNAME=	Sort-SQL-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sort-SQL
COMMENT=	Manipulate SQL sort strings
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sort/SQL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
