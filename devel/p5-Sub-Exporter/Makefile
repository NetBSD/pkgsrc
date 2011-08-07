# $NetBSD: Makefile,v 1.8 2011/08/07 12:53:46 adam Exp $

DISTNAME=	Sub-Exporter-0.982
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Exporter/
COMMENT=	Sophisticated exporter for custom-built routines
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Install>=0.92:../../devel/p5-Sub-Install
DEPENDS+=	p5-Params-Util>=0.14:../../devel/p5-Params-Util
DEPENDS+=	p5-Data-OptList>=0.1:../../devel/p5-Data-OptList

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sub/Exporter/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
