# $NetBSD: Makefile,v 1.1.1.1 2010/01/16 15:03:57 sno Exp $

DISTNAME=	Debug-Client-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Debug/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Debug-Client/
COMMENT=	Client side code for perl debugger
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST= auto/Debug/Client/.packlist
PERL5_MODULE_TYPE=	Module::Install

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
