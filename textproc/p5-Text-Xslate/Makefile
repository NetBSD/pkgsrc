# $NetBSD: Makefile,v 1.2 2012/03/15 01:17:28 joerg Exp $
#

DISTNAME=	Text-Xslate-1.5007
PKGNAME=	p5-${DISTNAME:S/007/.7/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Xslate/
COMMENT=	Scalable template engine for Perl5
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

DEPENDS+=	p5-Any-Moose>=0.13:../../devel/p5-Any-Moose
DEPENDS+=	p5-Data-MessagePack>=0.30:../../devel/p5-Data-MessagePack
DEPENDS+=	p5-Mouse>=0.61:../../devel/p5-Mouse
DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires

PERL5_PACKLIST=	auto/Text/Xslate/.packlist
USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
