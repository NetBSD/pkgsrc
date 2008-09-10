# $NetBSD: Makefile,v 1.1.1.1 2008/09/10 18:31:54 he Exp $
#

DISTNAME=		Test-POE-Server-TCP-0.12
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-POE-Server-TCP/
COMMENT=		POE Component providing TCP server services for tests

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-POE-[0-9]*:../../devel/p5-POE

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/POE/Server/TCP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
