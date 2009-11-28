# $NetBSD: Makefile,v 1.1.1.1 2009/11/28 07:29:02 seb Exp $

DISTNAME=	POE-Component-Schedule-0.92
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Component-Schedule/
COMMENT=	Schedule POE events using DateTime::Set iterators
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-POE>=1.003:../../devel/p5-POE
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Set>=0.25:../../time/p5-DateTime-Set
DEPENDS+=	p5-DateTime-TimeZone-[0-9]*:../../time/p5-DateTime-TimeZone

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/POE/Component/Schedule/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
