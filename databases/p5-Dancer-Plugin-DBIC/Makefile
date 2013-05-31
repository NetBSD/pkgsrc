# $NetBSD: Makefile,v 1.3 2013/05/31 12:39:52 wiz Exp $

DISTNAME=	Dancer-Plugin-DBIC-0.1601
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Dancer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Dancer-Plugin-DBIC/
COMMENT=	DBIx::Class interface for Dancer applications
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Dancer-[0-9]*:../../www/p5-Dancer

# recommended ...
DEPENDS+=	p5-DBIx-Class-Schema-Loader>=0.07002:../../databases/p5-DBIx-Class-Schema-Loader

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Dancer/Plugin/DBIC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
