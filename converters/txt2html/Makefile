# $NetBSD: Makefile,v 1.28 2018/08/22 09:43:09 wiz Exp $
#

DISTNAME=		txt2html-2.51
PKGREVISION=		5
CATEGORIES=		converters www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=txt2html/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://txt2html.sourceforge.net/
COMMENT=		Plain text to HTML convertor
LICENSE=		${PERL5_LICENSE}

REPLACE_PERL=		scripts/txt2html

PERL5_CONFIGURE=	yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/TextToHTML/.packlist

DEPENDS+=		p5-Getopt-ArgvFile-[0-9]*:../../devel/p5-Getopt-ArgvFile
DEPENDS+=		p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
