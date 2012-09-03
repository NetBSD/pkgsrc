# $NetBSD: Makefile,v 1.2 2012/09/03 11:38:58 sno Exp $
#

DISTNAME=	Module-Install-ReadmeFromPod-0.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Install-ReadmeFromPod/
COMMENT=	Module::Install extension to automatically convert POD to a README
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Capture-Tiny>=0.05:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Module-Install>=0.85:../../devel/p5-Module-Install

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/Install/ReadmeFromPod/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
