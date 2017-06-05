# $NetBSD: Makefile,v 1.13 2017/06/05 14:22:27 ryoon Exp $

DISTNAME=	DBIx-Class-DynamicDefault-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class-DynamicDefault/
COMMENT=	DBIx::Class component to automatically set and update fields
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/DynamicDefault/.packlist

DEPENDS+=	p5-DBIx-Class>=0.08127:../../databases/p5-DBIx-Class

BUILD_DEPENDS+=	p5-DBICx-TestDatabase-[0-9]*:../../databases/p5-DBICx-TestDatabase

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
