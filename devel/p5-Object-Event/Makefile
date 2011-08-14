# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:25 obache Exp $
#

DISTNAME=		Object-Event-1.21
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Object-Event/
COMMENT=		Perl 5 class that provides an event callback interface
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Object/Event/.packlist

DEPENDS+=	p5-AnyEvent>=3.5:../../devel/p5-AnyEvent
DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
