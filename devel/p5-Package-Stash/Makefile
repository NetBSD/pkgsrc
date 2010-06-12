# $NetBSD: Makefile,v 1.1.1.1 2010/06/12 20:44:03 seb Exp $
#

DISTNAME=	Package-Stash-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Package/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Package-Stash/
COMMENT=	Perl 5 module providing routines for manipulating stashes
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Package/Stash/.packlist

DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
