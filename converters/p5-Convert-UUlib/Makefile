# $NetBSD: Makefile,v 1.20 2008/06/20 01:09:09 joerg Exp $

DISTNAME=		Convert-UUlib-1.08
PKGNAME=		p5-${DISTNAME}0
SVR4_PKGNAME=		p5uul
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Convert-UUlib/
COMMENT=		Perl5 module interface to the uulib library

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Convert/UUlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
