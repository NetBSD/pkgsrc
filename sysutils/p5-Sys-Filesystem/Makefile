# $NetBSD: Makefile,v 1.1.1.1 2008/08/09 05:44:41 obache Exp $
#

DISTNAME=		Sys-Filesystem-1.22
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		sysutils devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Sys-Filesystem/
COMMENT=		Retrieve list of filesystems and their properties

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=		auto/Sys/Filesystem/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
