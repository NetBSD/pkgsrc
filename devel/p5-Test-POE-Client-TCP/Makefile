# $NetBSD: Makefile,v 1.4 2011/11/23 11:07:16 hiramatsu Exp $
#

DISTNAME=		Test-POE-Client-TCP-1.10
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-POE-Client-TCP/
COMMENT=		POE Component providing TCP client services for test cases
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/POE/Client/TCP/.packlist

DEPENDS+=	p5-POE>=1.28:../../devel/p5-POE

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
