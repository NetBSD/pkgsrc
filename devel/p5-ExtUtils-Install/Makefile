# $NetBSD: Makefile,v 1.4 2009/06/13 06:46:45 rillig Exp $

DISTNAME=	ExtUtils-Install-1.52
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-Install/
COMMENT=	Install files from here to there

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/ExtUtils/Install/.packlist
PERL5_MODULE_TYPE=	Module::Build

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
