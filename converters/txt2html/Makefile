# $NetBSD: Makefile,v 1.39 2026/07/16 19:01:33 wiz Exp $
#

DISTNAME=		txt2html-2.51
PKGREVISION=		13
CATEGORIES=		converters www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=txt2html/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://txt2html.sourceforge.net/
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
