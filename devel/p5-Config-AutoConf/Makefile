# $NetBSD: Makefile,v 1.9 2013/05/31 12:40:11 wiz Exp $

DISTNAME=	Config-AutoConf-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AM/AMBS/irConfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-AutoConf/
COMMENT=	Perl 5 module to implement some of AutoConf macros in pure perl
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Config/AutoConf/.packlist

DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
DEPENDS+=	{perl>=5.14.1,p5-ExtUtils-CBuilder>=0.23}:../../devel/p5-ExtUtils-CBuilder

ALL_ENV+=	TMPDIR=${WRKDIR}/tmp

pre-configure:
	${MKDIR} ${WRKDIR}/tmp

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
