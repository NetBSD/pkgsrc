# $NetBSD: Makefile,v 1.12 2008/06/12 02:14:37 joerg Exp $

DISTNAME=		Mac-Macbinary-0.06
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mmb
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mac/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl5 module for decoding Macbinary files

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Mac/Macbinary/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
