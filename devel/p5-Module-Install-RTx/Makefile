# $NetBSD: Makefile,v 1.25 2019/08/11 13:19:51 wiz Exp $

DISTNAME=	Module-Install-RTx-0.40
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Install-RTx
COMMENT=	Perl5 module for building and installing RT extensions
LICENSE=	mit

DEPENDS+=	p5-Module-Install-[0-9]*:../../devel/p5-Module-Install

PERL5_PACKLIST=		auto/Module/Install/RTx/.packlist

SUBST_CLASSES+=         manpath
SUBST_STAGE.manpath=    pre-configure
SUBST_FILES.manpath=    lib/Module/Install/RTx.pm
SUBST_VARS.manpath=	PREFIX PKGMANDIR

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
