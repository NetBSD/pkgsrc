# $NetBSD: Makefile,v 1.12 2014/10/02 11:46:41 wen Exp $
#

DISTNAME=	Log-Report-1.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Report/
COMMENT=	Report a problem, pluggable handlers, and language support
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.86}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Pod>=1.00:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Log-Report-Optional>=0:../../devel/p5-Log-Report-Optional

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Log/Report/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
