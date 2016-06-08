# $NetBSD: Makefile,v 1.5 2016/06/08 19:23:08 wiz Exp $
#

DISTNAME=	Log-Dispatch-Perl-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Dispatch-Perl/
COMMENT=	TODO: Short description of the package
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Log-Dispatch>=1.16:../../devel/p5-Log-Dispatch

PERL5_PACKLIST=	auto/Log/Dispatch/Perl/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
