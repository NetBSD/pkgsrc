# $NetBSD: Makefile,v 1.11 2001/11/26 06:49:52 jlam Exp $
#

DISTNAME=	IO-stringy-2.108
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5isr
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zeegee.com/code/perl/IO-stringy/
COMMENT=	Perl class for I/O on in-core objects like strings and arrays

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO-stringy/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
