# $NetBSD: Makefile,v 1.5 2009/01/20 23:48:57 he Exp $

DISTNAME=	Set-Object-1.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Set/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Set-Object/
COMMENT=	Perl module to manage sets of objects

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Set/Object/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
