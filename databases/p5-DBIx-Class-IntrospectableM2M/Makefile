# $NetBSD: Makefile,v 1.15 2019/08/11 13:18:27 wiz Exp $

DISTNAME=	DBIx-Class-IntrospectableM2M-0.001002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/DBIx::Class::IntrospectableM2M
COMMENT=	Introspect many-to-many shortcuts

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/DBIx/Class/IntrospectableM2M/.packlist

DEPENDS+=	p5-DBIx-Class>=0.07005:../../databases/p5-DBIx-Class

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
