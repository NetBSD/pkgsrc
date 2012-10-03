# $NetBSD: Makefile,v 1.2 2012/10/03 21:55:12 wiz Exp $

DISTNAME=		Log-Dispatch-Array-1.001
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Log-Dispatch-Array/
COMMENT=		Perl 5 module to log events to an array
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Log-Dispatch-[0-9]*:../../devel/p5-Log-Dispatch

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

PERL5_PACKLIST=		auto/Log/Dispatch/Array/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
