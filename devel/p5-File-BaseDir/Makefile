# $NetBSD: Makefile,v 1.17 2013/05/31 12:40:19 wiz Exp $

DISTNAME=		File-BaseDir-0.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-BaseDir/
COMMENT=		Perl module for the XDG Base Directory Specification
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

SHAREDIR=		${PREFIX}/share
SHAREDIR_SPLIT=		${SHAREDIR:S/\// /g}
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-configure
SUBST_FILES.paths=	lib/File/BaseDir.pm t/01_vars.t t/03_OO.t
SUBST_SED.paths=	-e 's|@SHAREDIR_SPLIT@|${SHAREDIR_SPLIT}|g'

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/File/BaseDir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
