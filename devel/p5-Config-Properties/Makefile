# $NetBSD: Makefile,v 1.2 2012/10/03 21:54:48 wiz Exp $
#

DISTNAME=	Config-Properties-1.73
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
