# $NetBSD: Makefile,v 1.14 2022/06/28 11:32:41 wiz Exp $
#

DISTNAME=	Log-Dispatch-Perl-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Log-Dispatch-Perl
COMMENT=	Logging alternative using standard Perl core functions
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Log-Dispatch>=1.16:../../devel/p5-Log-Dispatch

PERL5_PACKLIST=	auto/Log/Dispatch/Perl/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
