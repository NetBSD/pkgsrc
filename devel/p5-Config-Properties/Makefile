# $NetBSD: Makefile,v 1.1.1.1 2012/03/08 11:20:04 fhajny Exp $
#

DISTNAME=	Config-Properties-1.73
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-Properties/
COMMENT=	Read and write property files
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-File-Temp>=0:../../devel/p5-File-Temp

PERL5_PACKLIST=	auto/Config/Properties/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
