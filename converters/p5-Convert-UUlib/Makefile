# $NetBSD: Makefile,v 1.26 2010/08/21 16:32:48 seb Exp $

DISTNAME=		Convert-UUlib-1.33
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5uul
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Convert-UUlib/
COMMENT=		Perl5 module interface to the uulib library
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Convert/UUlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
