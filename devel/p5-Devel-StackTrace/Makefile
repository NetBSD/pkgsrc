# $NetBSD: Makefile,v 1.24 2009/07/18 17:45:52 sno Exp $
#

DISTNAME=		Devel-StackTrace-1.22
PKGNAME=		p5-${DISTNAME}00
SVR4_PKGNAME=		p5dst
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Devel-StackTrace/
COMMENT=		Perl5 module for stack trace and stack trace frame objects
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Devel/StackTrace/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
