# $NetBSD: Makefile,v 1.1.1.1 2001/07/03 14:07:08 abs Exp $

DISTNAME=		MIME-Lite-2.111
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		norm@sandbox.org.uk
COMMENT=		perl5 module for simple creation of MIME email messages

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MIME/Lite/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
