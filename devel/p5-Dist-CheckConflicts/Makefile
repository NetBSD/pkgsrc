# $NetBSD: Makefile,v 1.1.1.1 2011/08/16 20:50:54 wiz Exp $

DISTNAME=	Dist-CheckConflicts-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Dist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Dist-CheckConflicts/
COMMENT=	Perl 5 module to declare version conflicts for your dist
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-List-MoreUtils>=0.12:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Dist/CheckConflicts/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
