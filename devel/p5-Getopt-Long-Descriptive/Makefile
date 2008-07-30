# $NetBSD: Makefile,v 1.3 2008/07/30 13:15:37 he Exp $

DISTNAME=		Getopt-Long-Descriptive-0.074
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Getopt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Getopt-Long-Descriptive/
COMMENT=		Perl 5 module providing Getopt::Long with usage text

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=		p5-Params-Validate>=0.74:../../devel/p5-Params-Validate

PERL5_PACKLIST=	auto/Getopt/Long/Descriptive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
