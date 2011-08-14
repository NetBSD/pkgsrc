# $NetBSD: Makefile,v 1.18 2011/08/14 07:47:43 obache Exp $
#

DISTNAME=		txt2html-2.44
PKGREVISION=		3
CATEGORIES=		converters www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=txt2html/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://txt2html.sourceforge.net/
COMMENT=		Plain text to HTML convertor

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL=		scripts/txt2html

PERL5_CONFIGURE=	yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/TextToHTML/.packlist

DEPENDS+=		p5-Getopt-Long-[0-9]*:../../devel/p5-Getopt-Long
DEPENDS+=		p5-Getopt-ArgvFile-[0-9]*:../../devel/p5-Getopt-ArgvFile
DEPENDS+=		p5-AppConfig-Std-[0-9]*:../../devel/p5-AppConfig-Std

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
