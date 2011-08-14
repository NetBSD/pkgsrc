# $NetBSD: Makefile,v 1.7 2011/08/14 12:26:40 obache Exp $

DISTNAME=	Test-Differences-0.500
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Test::Differences
COMMENT=	Test strings and data structures and show differences if not ok
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-Diff>=0.34:../../textproc/p5-Text-Diff

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Differences/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
