# $NetBSD: Makefile,v 1.20 2019/11/02 15:38:06 rillig Exp $

DISTNAME=	Sort-SQL-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
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
