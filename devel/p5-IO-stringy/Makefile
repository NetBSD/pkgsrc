# $NetBSD: Makefile,v 1.12 2002/10/13 22:22:48 seb Exp $
#

DISTNAME=	IO-stringy-2.108
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5isr
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zeegee.com/code/perl/IO-stringy/
COMMENT=	Perl class for I/O on in-core objects like strings and arrays

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO-stringy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
