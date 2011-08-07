# $NetBSD: Makefile,v 1.4 2011/08/07 05:39:38 adam Exp $

DISTNAME=	Acme-PlayCode-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Acme/}
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SA/SARTAK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Acme-PlayCode/
COMMENT=	Perl5 module for code transforming to avoid typical typing mistakes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moose>=0.57:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Object-Pluggable>=0.0008:../../devel/p5-MooseX-Object-Pluggable
DEPENDS+=	p5-PPI>=1.201:../../devel/p5-PPI
DEPENDS+=	p5-Path-Class>=0.16:../../devel/p5-Path-Class

PERL5_PACKLIST=		auto/Acme/PlayCode/.packlist
PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
