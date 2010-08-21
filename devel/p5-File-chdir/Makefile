# $NetBSD: Makefile,v 1.7 2010/08/21 16:33:46 seb Exp $
#

DISTNAME=	File-chdir-0.1002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-chdir/
COMMENT=	Perl module with a more sensible way to change directories

DEPENDS+=	p5-PathTools>=3.27:../../devel/p5-PathTools

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/chdir/.packlist

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
