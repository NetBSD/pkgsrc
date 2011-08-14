# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:15 obache Exp $
#

DISTNAME=	Log-Any-Adapter-Log4perl-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Any-Adapter-Log4perl/
COMMENT=	Adapter to use Log::Log4perl with Log::Any
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Log-Any-Adapter-[0-9]*:../../devel/p5-Log-Any-Adapter
DEPENDS+=	p5-Log-Log4perl>=1.00:../../devel/p5-Log-Log4perl

PERL5_PACKLIST=		auto/Log/Any/Adapter/Log4perl/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
