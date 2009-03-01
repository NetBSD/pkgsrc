# $NetBSD: Makefile,v 1.1 2009/03/01 23:33:58 sno Exp $

DISTNAME=	ExtUtils-Manifest-1.56
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ExtUtils-Manifest/
COMMENT=	Perl utilities to write and check a MANIFEST file

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/ExtUtils/Manifest/.packlist
PERL5_MODULE_TYPE=	Module::Build

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
