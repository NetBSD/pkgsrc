# $NetBSD: Makefile,v 1.7 2011/08/14 12:26:37 obache Exp $
#

DISTNAME=	Task-Weaken-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Task/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist//Task-Weaken/
COMMENT=	Perl 5 module to ensure that a platform has weaken support
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE=	Module::Install
PERL5_PACKLIST=	auto/Task/Weaken/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
