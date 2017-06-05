# $NetBSD: Makefile,v 1.37 2017/06/05 14:23:07 ryoon Exp $

DISTNAME=	IO-Tty-1.12
PKGNAME=	p5-${DISTNAME:C/T/t/}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Tty/
COMMENT=	Another Perl class for I/O on tty and pseudo-tty devices
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/IO/Tty/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
