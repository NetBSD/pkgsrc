# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:41 obache Exp $
#

DISTNAME=		Test-HexString-0.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-HexString/
COMMENT=		Perl5 module to test binary strings with hex dump diagnostics
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Test/HexString/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
