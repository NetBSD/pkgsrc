# $NetBSD: Makefile,v 1.1.1.1 2001/03/25 06:07:50 mjl Exp $
#

DISTNAME=       Text-Wrapper-1.000
PKGNAME=        p5-Text-Wrapper-1.0
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module that provides simple word wrapping

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Text/Wrapper/.packlist

do-configure:
	@cd ${WRKSRC} && ${ECHO} >.test && \
		${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
