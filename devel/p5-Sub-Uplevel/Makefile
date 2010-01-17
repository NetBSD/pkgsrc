# $NetBSD: Makefile,v 1.14 2010/01/17 00:55:42 sno Exp $
#

DISTNAME=		Sub-Uplevel-0.22
PKGNAME=		p5-${DISTNAME}00
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Sub-Uplevel/
COMMENT=		Apparently run a function in a higher stack frame
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Sub/Uplevel/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
