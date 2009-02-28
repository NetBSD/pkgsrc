# $NetBSD: Makefile,v 1.29 2009/02/28 16:21:47 adrianp Exp $
#

DISTNAME=	Test-Harness-3.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-Harness/
COMMENT=	Run Perl standard test scripts with statistics

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST= auto/Test/Harness/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
