# $NetBSD: Makefile,v 1.5 2005/11/22 23:14:52 wiz Exp $
#

DISTNAME=	prefork-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/ADAMK/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/prefork/
COMMENT=	Optimize module loading across forking and non-forking scenarios

BUILD_DEPENDS+=	p5-ExtUtils-AutoInstall>=0.59:../../devel/p5-ExtUtils-AutoInstall

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/prefork/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
