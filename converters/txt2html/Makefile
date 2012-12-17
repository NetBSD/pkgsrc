# $NetBSD: Makefile,v 1.22 2012/12/17 13:15:39 obache Exp $
#

DISTNAME=		txt2html-2.51
CATEGORIES=		converters www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=txt2html/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://txt2html.sourceforge.net/
COMMENT=		Plain text to HTML convertor
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES= overwrite pkgviews

REPLACE_PERL=		scripts/txt2html

PERL5_CONFIGURE=	yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/TextToHTML/.packlist

DEPENDS+=		p5-Getopt-ArgvFile-[0-9]*:../../devel/p5-Getopt-ArgvFile
DEPENDS+=		p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
