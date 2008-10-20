# $NetBSD: Makefile,v 1.23 2008/10/20 21:55:32 he Exp $

DISTNAME=		Convert-UUlib-1.12
PKGNAME=		p5-${DISTNAME}
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
