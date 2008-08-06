# $NetBSD: Makefile,v 1.2 2008/08/06 21:09:54 he Exp $

DISTNAME=	Test-Differences-0.4801
PKGNAME=	p5-${DISTNAME:S/4801/48.01/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Test::Differences
COMMENT=	Test strings and data structures and show differences if not ok

DEPENDS+=      	p5-Text-Diff>=0.34:../../textproc/p5-Text-Diff

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Differences/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
