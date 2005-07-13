# $NetBSD: Makefile,v 1.3 2005/07/13 18:01:30 jlam Exp $
#

DISTNAME=	prefork-0.04
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
