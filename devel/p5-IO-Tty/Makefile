# $NetBSD: Makefile,v 1.20 2008/02/09 16:34:43 rhaen Exp $
#

DISTNAME=	IO-Tty-1.07
PKGNAME=	p5-${DISTNAME:C/T/t/}
SVR4_PKGNAME=	p5itt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	rhaen@NetBSD.org
COMMENT=	Another Perl class for I/O on tty and pseudo-tty devices

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir


PERL5_PACKLIST=		auto/IO/Tty/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
