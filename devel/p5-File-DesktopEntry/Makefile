# $NetBSD: Makefile,v 1.3 2008/10/19 19:17:54 he Exp $

DISTNAME=	File-DesktopEntry-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-DesktopEntry/
COMMENT=	Perl module for handling .desktop files

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_USE_PACKLIST=	no

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
