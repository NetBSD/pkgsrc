# $NetBSD: Makefile,v 1.1.1.1 2009/02/03 06:01:40 seb Exp $
#

DISTNAME=	Config-Auto-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-Auto/
COMMENT=	Perl 5 module providing a magical config file parser

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Config/Auto/.packlist

DEPENDS+=	p5-Config-IniFiles-[0-9]*:../../devel/p5-Config-IniFiles
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
