# $NetBSD: Makefile,v 1.9 2016/06/08 19:23:07 wiz Exp $

DISTNAME=		Log-Dispatch-Array-1.003
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Log-Dispatch-Array/
COMMENT=		Perl 5 module to log events to an array
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-Log-Dispatch-[0-9]*:../../devel/p5-Log-Dispatch

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

PERL5_PACKLIST=		auto/Log/Dispatch/Array/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
