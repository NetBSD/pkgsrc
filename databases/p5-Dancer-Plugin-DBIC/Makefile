# $NetBSD: Makefile,v 1.18 2022/06/28 11:31:26 wiz Exp $

DISTNAME=	Dancer-Plugin-DBIC-0.2104
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Dancer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Dancer-Plugin-DBIC
COMMENT=	DBIx::Class interface for Dancer applications
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Dancer>=1.3098:../../www/p5-Dancer
DEPENDS+=	p5-DBICx-Sugar>=0:../../databases/p5-DBICx-Sugar

# recommended ...
DEPENDS+=	p5-DBIx-Class-Schema-Loader>=0.07002:../../databases/p5-DBIx-Class-Schema-Loader

PERL5_PACKLIST=		auto/Dancer/Plugin/DBIC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
