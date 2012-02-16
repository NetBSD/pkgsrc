# $NetBSD: Makefile,v 1.8 2012/02/16 06:10:10 sno Exp $

DISTNAME=	Capture-Tiny-0.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DAGOLDEN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Capture-Tiny/
COMMENT=	Capture STDOUT and STDERR from Perl, XS or external programs
LICENSE=	apache-2.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Capture/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
