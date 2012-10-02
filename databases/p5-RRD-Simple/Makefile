# $NetBSD: Makefile,v 1.14 2012/10/02 17:10:43 tron Exp $

DISTNAME=	RRD-Simple-1.44
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	perl5 databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/N/NI/NICOLAW/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/RRD-Simple/
COMMENT=	RRD::Simple implementation for Perl
LICENSE=	apache-2.0

BUILD_DEPENDS+= p5-Test-Pod>=1.26:../../devel/p5-Test-Pod
BUILD_DEPENDS+= p5-Pod-Coverage>=0.18:../../textproc/p5-Pod-Coverage
BUILD_DEPENDS+= p5-Test-Pod-Coverage>=1.08:../../devel/p5-Test-Pod-Coverage
BUILD_DEPENDS+= p5-Test-Deep>=0.096:../../devel/p5-Test-Deep

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/RRD/Simple/.packlist
MAKE_PARAMS+=		< /dev/null

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
