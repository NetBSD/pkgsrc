# $NetBSD: Makefile,v 1.2 2013/05/31 12:40:48 wiz Exp $
#

DISTNAME=		Test-File-1.34
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-File/
COMMENT=		Test file attributes
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/File/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
