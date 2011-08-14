# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:37 obache Exp $
#

DISTNAME=	Tee-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DAGOLDEN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tee/
COMMENT=	Pure Perl emulation of GNU tee

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Tee/.packlist

DEPENDS+=	p5-Probe-Perl>=0:../../devel/p5-Probe-Perl
DEPENDS+=	p5-IPC-Run3>=0.033:../../devel/p5-IPC-Run3

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
