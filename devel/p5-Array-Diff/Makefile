# $NetBSD: Makefile,v 1.2 2009/05/17 14:16:11 sno Exp $
#

DISTNAME=	Array-Diff-0.05002
PKGNAME=	p5-${DISTNAME:S/05002/05.002/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Array/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Array-Diff/
COMMENT=	Perl 5 module to diff two arrays
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-Algorithm-Diff>0:../../devel/p5-Algorithm-Diff
DEPENDS+=	p5-Class-Accessor>0:../../devel/p5-Class-Accessor

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Array/Diff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
