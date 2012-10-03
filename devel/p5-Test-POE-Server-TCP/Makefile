# $NetBSD: Makefile,v 1.10 2012/10/03 21:55:44 wiz Exp $
#

DISTNAME=		Test-POE-Server-TCP-1.16
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-POE-Server-TCP/
COMMENT=		POE Component providing TCP server services for tests
LICENSE=		artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-POE>=1.004:../../devel/p5-POE

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/POE/Server/TCP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
