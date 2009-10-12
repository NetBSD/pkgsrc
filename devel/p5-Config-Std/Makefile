# $NetBSD: Makefile,v 1.4 2009/10/12 19:59:30 rhaen Exp $
#

DISTNAME=	Config-Std-0.0.5
PKGNAME=	p5-Config-Std-0.0.5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-Std/
COMMENT=	Perl 5 module providing a simple configuration-file system
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Std-[0-9]*:../../devel/p5-Class-Std
DEPENDS+=	p5-version-[0-9]*:../../devel/p5-version

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Config/Std/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
