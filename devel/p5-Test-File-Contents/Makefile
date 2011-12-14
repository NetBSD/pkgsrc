# $NetBSD: Makefile,v 1.6 2011/12/14 11:01:39 hiramatsu Exp $

DISTNAME=	Test-File-Contents-0.20
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tfc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-File-Contents/
COMMENT=	Perl5 module for test routines examining the contents of files
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Test/File/Contents/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
