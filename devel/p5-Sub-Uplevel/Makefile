# $NetBSD: Makefile,v 1.15 2010/08/21 16:34:27 seb Exp $
#

DISTNAME=		Sub-Uplevel-0.22
PKGNAME=		p5-${DISTNAME}00
PKGREVISION=		1
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
