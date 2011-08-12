# $NetBSD: Makefile,v 1.9 2011/08/12 19:09:59 adam Exp $

DISTNAME=	File-chdir-0.1004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-chdir/
COMMENT=	Perl module with a more sensible way to change directories
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.10.0,p5-PathTools>=3.27}:../../devel/p5-PathTools

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/File/chdir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
