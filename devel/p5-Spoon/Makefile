# $NetBSD: Makefile,v 1.17 2011/10/06 13:05:28 hiramatsu Exp $

DISTNAME=	Spoon-0.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-${AUTHOR_DIR}/}
AUTHOR_DIR=	authors/id/I/IN/INGY

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Spoon/
COMMENT=	Spiffy Application Building Framework
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-IO-All>=0.32:../../devel/p5-IO-All
DEPENDS+=	p5-Spiffy>=0.22:../../devel/p5-Spiffy
DEPENDS+=	p5-Template-Toolkit>=2.10:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/Spoon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
