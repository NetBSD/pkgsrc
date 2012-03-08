# $NetBSD: Makefile,v 1.1.1.1 2012/03/08 11:20:57 fhajny Exp $
#

DISTNAME=	Data-MessagePack-0.39
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-MessagePack/
COMMENT=	MessagePack serialising/deserialising
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires

PERL5_PACKLIST=	auto/Data/MessagePack/.packlist
USE_LANGUAGES=	c99

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
