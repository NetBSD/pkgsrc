# $NetBSD: Makefile,v 1.4 2008/11/17 22:08:17 he Exp $

DISTNAME=	Set-Object-1.26
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
