# $NetBSD: Makefile,v 1.8 2015/06/12 10:48:40 wiz Exp $

DISTNAME=	DBIx-Class-IntrospectableM2M-0.001001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?DBIx::Class::IntrospectableM2M
COMMENT=	Introspect many-to-many shortcuts

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBIx/Class/IntrospectableM2M/.packlist

DEPENDS+=	p5-DBIx-Class>=0.07005:../../databases/p5-DBIx-Class

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
