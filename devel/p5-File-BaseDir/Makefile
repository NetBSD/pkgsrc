# $NetBSD: Makefile,v 1.26 2017/06/05 14:22:58 ryoon Exp $

DISTNAME=		File-BaseDir-0.07
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-BaseDir/
COMMENT=		Perl module for the XDG Base Directory Specification
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-IPC-System-Simple-[0-9]*:../../devel/p5-IPC-System-Simple
# for make test
BUILD_DEPENDS+=		xdg-user-dirs-[0-9]*:../../x11/xdg-user-dirs
BUILD_DEPENDS+=		p5-File-Which-[0-9]*:../../devel/p5-File-Which

SHAREDIR=		${PREFIX}/share
SHAREDIR_SPLIT=		${SHAREDIR:S/\// /g}
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-configure
SUBST_FILES.paths=	lib/File/BaseDir.pm t/01_vars.t t/03_OO.t
SUBST_SED.paths=	-e 's|@SHAREDIR_SPLIT@|${SHAREDIR_SPLIT}|g'

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/File/BaseDir/.packlist

pre-test:
	${MKDIR} ${WRKDIR}/.home/.config/user-dirs.dirs

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
