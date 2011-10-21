# $NetBSD: Makefile,v 1.36 2011/10/21 07:10:20 hiramatsu Exp $
#

DISTNAME=	Module-CoreList-2.57
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mcl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-CoreList/
COMMENT=	Perl 5 module inventorying modules shipped with core Perl
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/CoreList/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
