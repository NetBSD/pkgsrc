# $NetBSD: Makefile,v 1.9 2011/08/14 12:26:35 obache Exp $

DISTNAME=	Set-Object-1.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Set-Object/
COMMENT=	Perl module to manage sets of objects
LICENSE=	artistic

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Set/Object/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
