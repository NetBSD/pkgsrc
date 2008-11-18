# $NetBSD: Makefile,v 1.6 2008/11/18 16:21:53 he Exp $

DISTNAME=	File-Copy-Recursive-0.37
PKGNAME=	p5-${DISTNAME}
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
