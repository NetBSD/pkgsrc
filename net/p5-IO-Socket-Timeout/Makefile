# $NetBSD: Makefile,v 1.3 2016/12/15 21:15:41 mef Exp $

DISTNAME=		IO-Socket-Timeout-0.32
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-Socket-Timeout/
COMMENT=		IO::Socket with read/write timeout
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-PerlIO-via-Timeout>=0.32:../../devel/p5-PerlIO-via-Timeout
# for make test
BUILD_DEPENDS+=		p5-Test-TCP-[0-9]*:../../net/p5-Test-TCP

PERL5_PACKLIST=		auto/IO/Socket/Timeout/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
