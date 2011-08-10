# $NetBSD: Makefile,v 1.3 2011/08/10 08:20:17 adam Exp $

DISTNAME=	Config-Auto-0.38
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BI/BINGOS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-Auto/
COMMENT=	Perl 5 module providing a magical config file parser
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Config-IniFiles-[0-9]*:../../devel/p5-Config-IniFiles
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Config/Auto/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
