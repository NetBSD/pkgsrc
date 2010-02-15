# $NetBSD: Makefile,v 1.9 2010/02/15 15:33:21 sno Exp $

DISTNAME=		Getopt-Long-Descriptive-0.084
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Getopt-Long-Descriptive/
COMMENT=		Perl 5 module providing Getopt::Long with usage text
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Params-Validate>=0.74:../../devel/p5-Params-Validate
DEPENDS+=		p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter

PERL5_PACKLIST=	auto/Getopt/Long/Descriptive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
