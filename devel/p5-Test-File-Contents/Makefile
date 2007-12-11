# $NetBSD: Makefile,v 1.2 2007/12/11 11:56:54 rhaen Exp $

DISTNAME=	Test-File-Contents-0.05
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tfc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-File-Contents//
COMMENT=	Perl5 module for test routines examining the contents of files

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Test/File/Contents/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
