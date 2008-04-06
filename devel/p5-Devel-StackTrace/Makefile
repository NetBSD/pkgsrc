# $NetBSD: Makefile,v 1.18 2008/04/06 14:53:57 heinz Exp $
#

DISTNAME=		Devel-StackTrace-1.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dst
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Devel-StackTrace/
COMMENT=		Perl5 module for stack trace and stack trace frame objects

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Test-Simple>=0.46:../../devel/p5-Test-Simple

USE_LANGUAGES=		# none

PERL5_PACKLIST=		auto/Devel/StackTrace/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
