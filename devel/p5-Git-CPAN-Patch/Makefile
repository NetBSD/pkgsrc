# $NetBSD: Makefile,v 1.5 2011/08/16 08:30:16 adam Exp $

DISTNAME=	Git-CPAN-Patch-0.6.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Git/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Git-CPAN-Patch/
COMMENT=	Patch CPAN modules using Git
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base
DEPENDS+=	p5-BackPAN-Index>=0.39:../../devel/p5-BackPAN-Index
DEPENDS+=	p5-CLASS-[0-9]*:../../devel/p5-CLASS
DEPENDS+=	p5-File-chdir-[0-9]*:../../devel/p5-File-chdir
DEPENDS+=	p5-File-chmod-[0-9]*:../../sysutils/p5-File-chmod

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Git/CPAN/Patch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
