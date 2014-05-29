# $NetBSD: Makefile,v 1.13 2014/05/29 23:37:29 wiz Exp $

DISTNAME=	File-Copy-Recursive-0.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	sysutils devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-module/File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Copy-Recursive/
COMMENT=	Perl extension for recursively copying files and directories

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/File/Copy/Recursive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
