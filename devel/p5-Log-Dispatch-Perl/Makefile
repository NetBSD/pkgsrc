# $NetBSD: Makefile,v 1.10 2019/09/16 00:10:25 nia Exp $
#

DISTNAME=	Log-Dispatch-Perl-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
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
