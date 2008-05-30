# $NetBSD: Makefile,v 1.1.1.1 2008/05/30 11:55:51 abs Exp $

DISTNAME=	Text-SimpleTable-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SR/SRI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-SimpleTable/
COMMENT=	Simple Eyecandy ASCII Tables

PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Text/SimpleTable/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
