# $NetBSD: Makefile,v 1.2 2012/10/03 21:55:05 wiz Exp $
#

DISTNAME=	Hash-FieldHash-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Hash-FieldHash/
COMMENT=	Lightweight field hash for inside-out objects
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Test-LeakTrace>=0:../../devel/p5-Test-LeakTrace

PERL5_PACKLIST=	auto/Hash/FieldHash/.packlist
USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
