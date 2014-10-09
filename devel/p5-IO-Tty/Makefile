# $NetBSD: Makefile,v 1.33 2014/10/09 14:06:20 wiz Exp $
#

DISTNAME=	IO-Tty-1.12
PKGNAME=	p5-${DISTNAME:C/T/t/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Tty/
COMMENT=	Another Perl class for I/O on tty and pseudo-tty devices
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/IO/Tty/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
