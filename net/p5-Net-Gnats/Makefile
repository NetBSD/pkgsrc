# $NetBSD: Makefile,v 1.20 2016/06/08 19:24:11 wiz Exp $
#

DISTNAME=	Net-Gnats-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnatsperl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnatsperl.sourceforge.net/
#HOMEPAGE=	http://search.cpan.org/dist/Net-Gnats/
COMMENT=	Perl interface to the gnatsd daemon
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-ExtUtils-MakeMaker-Coverage-[0-9]*:../../devel/p5-ExtUtils-MakeMaker-Coverage
DEPENDS+=	p5-Object-Accessor-[0-9]*:../../devel/p5-Object-Accessor

PERL5_PACKLIST=		auto/Net/Gnats/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
