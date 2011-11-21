# $NetBSD: Makefile,v 1.9 2011/11/21 08:44:48 hiramatsu Exp $

DISTNAME=	Devel-PPPort-3.20
PKGNAME=	p5-${DISTNAME:S/_/./}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MH/MHX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-PPPort/
COMMENT=	Perl5 module to bring newer features to older perl
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Devel/PPPort/.packlist
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
