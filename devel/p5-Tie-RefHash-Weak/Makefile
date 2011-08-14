# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:46 obache Exp $
#

DISTNAME=	Tie-RefHash-Weak-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-RefHash-Weak/
COMMENT=	Perl 5 Tie::RefHash subclass with weakened references in the keys

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Tie/RefHash/Weak/.packlist

DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Tie-RefHash>=1.34:../../devel/p5-Tie-RefHash
DEPENDS+=	p5-Variable-Magic-[0-9]*:../../devel/p5-Variable-Magic

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
