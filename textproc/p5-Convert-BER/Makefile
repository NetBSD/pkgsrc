# $NetBSD: Makefile,v 1.6 2001/10/31 14:39:19 tv Exp $
#

DISTNAME=	Convert-BER-1.31
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ber
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl class to encode and decode objects using Basic Encoding Rules (BER)

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Convert/BER/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
