# $NetBSD: Makefile,v 1.16 2011/08/14 12:26:36 obache Exp $

DISTNAME=	Spoon-0.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-${AUTHOR_DIR}/}
AUTHOR_DIR=	authors/id/I/IN/INGY

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spiffy Application Building Framework

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-IO-All>=0.32:../../devel/p5-IO-All
DEPENDS+=	p5-Spiffy>=0.22:../../devel/p5-Spiffy
DEPENDS+=	p5-Template-Toolkit>=2.10:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/Spoon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
