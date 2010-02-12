# $NetBSD: Makefile,v 1.1.1.1 2010/02/12 15:31:13 sno Exp $
#

DISTNAME=	Log-Any-Adapter-Dispatch-0.05
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Any-Adapter/
COMMENT=	Log::Any adapter uses Log::Dispatch for logging
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Log-Any-Adapter-[0-9]*:../../devel/p5-Log-Any-Adapter
DEPENDS+=	p5-Log-Dispatch>=2.26:../../devel/p5-Log-Dispatch

PERL5_PACKLIST=		auto/Log/Any/Adapter/Dispatch/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
