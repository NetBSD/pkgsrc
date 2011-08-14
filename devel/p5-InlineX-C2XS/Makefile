# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:13 obache Exp $
#

DISTNAME=	InlineX-C2XS-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Inline/SISYPHUS/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/dist/InlineX-C2XS/
COMMENT=	Convert from Inline C code to XS
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Inline>=0.45:../../devel/p5-Inline

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/InlineX/C2XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
