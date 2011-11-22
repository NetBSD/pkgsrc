# $NetBSD: Makefile,v 1.6 2011/11/22 11:18:34 hiramatsu Exp $

DISTNAME=	Devel-CheckLib-0.95
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-CheckLib/
COMMENT=	Perl extension to check that a library is available
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-IO-CaptureOutput>=1.08.01:../../devel/p5-IO-CaptureOutput

PERL5_PACKLIST=		auto/Devel/CheckLib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
