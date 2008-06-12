# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:26 joerg Exp $
#

DISTNAME=	Task-Weaken-0.99
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Task/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist//Task-Weaken/
COMMENT=	Perl 5 module to ensure that a platform has weaken support

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Task/Weaken/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
