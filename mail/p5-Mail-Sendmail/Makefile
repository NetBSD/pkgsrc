# $NetBSD: Makefile,v 1.1.1.1 2001/04/16 18:13:39 jtb Exp $

DISTNAME=	Mail-Sendmail-0.78
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://alma.ch/perl/
COMMENT=	perl5 module dedicated to Sendmail

DEPENDS+=	p5-MIME-Base64-*:../../converters/p5-MIME-Base64

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Mail/Sendmail/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
