# $NetBSD: Makefile,v 1.2 2009/05/21 15:04:24 sno Exp $
#

DISTNAME=	Class-Mix-0.003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Mix/
COMMENT=	Perl 5 module providing dynamic class mixing
#LICENSE=	artistic OR gnu-gpl-v2

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Class/Mix/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
