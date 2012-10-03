# $NetBSD: Makefile,v 1.10 2012/10/03 21:57:40 wiz Exp $

DISTNAME=	File-Copy-Recursive-0.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	sysutils devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-module/File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Copy-Recursive/
COMMENT=	Perl extension for recursively copying files and directories

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/File/Copy/Recursive/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
