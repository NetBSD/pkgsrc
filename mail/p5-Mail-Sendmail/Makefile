# $NetBSD: Makefile,v 1.2 2001/09/27 23:18:22 jlam Exp $

DISTNAME=	Mail-Sendmail-0.78
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://alma.ch/perl/
COMMENT=	perl5 module dedicated to Sendmail

DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Mail/Sendmail/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
