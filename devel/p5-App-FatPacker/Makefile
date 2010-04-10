# $NetBSD: Makefile,v 1.1.1.1 2010/04/10 13:05:09 seb Exp $
#

DISTNAME=		App-FatPacker-0.009001
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/App-FatPacker/
COMMENT=		Perl5 module to pack your dependencies onto your script file
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/App/FatPacker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
