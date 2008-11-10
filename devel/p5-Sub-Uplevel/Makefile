# $NetBSD: Makefile,v 1.12 2008/11/10 19:43:32 wiz Exp $
#

DISTNAME=		Sub-Uplevel-0.2002
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Sub-Uplevel/
COMMENT=		Apparently run a function in a higher stack frame

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Sub/Uplevel/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
