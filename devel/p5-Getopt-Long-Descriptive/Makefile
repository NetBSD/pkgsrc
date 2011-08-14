# $NetBSD: Makefile,v 1.13 2011/08/14 12:26:07 obache Exp $

DISTNAME=		Getopt-Long-Descriptive-0.086
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Getopt-Long-Descriptive/
COMMENT=		Perl 5 module providing Getopt::Long with usage text
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Params-Validate>=0.74:../../devel/p5-Params-Validate
DEPENDS+=		p5-Sub-Exporter>=0.972:../../devel/p5-Sub-Exporter

PERL5_PACKLIST=	auto/Getopt/Long/Descriptive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
