# $NetBSD: Makefile,v 1.2 2008/12/17 15:51:08 joerg Exp $
#

DISTNAME=	Test-YAML-Valid-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-YAML-Valid/
COMMENT=	Perl 5 module to test for valid YAML

DEPENDS+=	p5-YAML-Syck>=0.60:../../textproc/p5-YAML-Syck

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST= auto/Test/YAML/Valid/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
