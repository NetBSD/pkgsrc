# $NetBSD: Makefile,v 1.22 2023/07/06 09:38:24 wiz Exp $

DISTNAME=	DBIx-Class-InflateColumn-IP-0.02003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBIx-Class-InflateColumn-IP
COMMENT=	DBIx::Class component to auto-create NetAddr::IP objects from columns
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/DBIx/Class/InflateColumn/IP/.packlist

DEPENDS+=	p5-DBIx-Class>=0.07005:../../databases/p5-DBIx-Class
DEPENDS+=	p5-NetAddr-IP-[0-9]*:../../net/p5-NetAddr-IP
# For test really
TOOL_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
