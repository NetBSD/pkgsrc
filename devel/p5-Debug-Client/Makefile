# $NetBSD: Makefile,v 1.5 2012/09/11 08:24:02 sno Exp $

DISTNAME=	Debug-Client-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Debug/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Debug-Client/
COMMENT=	Client side code for perl debugger
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PadWalker>=1.9.2:../../devel/p5-PadWalker
DEPENDS+=	p5-Term-ReadLine-Perl>=1.0303:../../devel/p5-Term-ReadLine-Perl

BUILD_DEPENDS+=	p5-Test-Class>=0.36:../../devel/p5-Test-Class
BUILD_DEPENDS+= p5-Test-Deep>=0.108:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	{perl>=5.14.2,p5-Test-Simple>=0.98}:../../devel/p5-Test-Simple

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Debug/Client/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
