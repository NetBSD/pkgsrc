# $NetBSD: Makefile,v 1.7 2015/06/12 10:49:38 wiz Exp $

DISTNAME=	Perl4-CoreLibs-0.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/Z/ZE/ZEFRAM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Perl4-CoreLibs/
COMMENT=	Libraries historically supplied with Perl 4
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Perl4/CoreLibs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
