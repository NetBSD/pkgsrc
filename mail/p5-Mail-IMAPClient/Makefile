# $NetBSD: Makefile,v 1.4 2001/10/18 15:20:26 veego Exp $
#

DISTNAME=       Mail-IMAPClient-1.07
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5mic
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module for talking to RFC-2060 IMAP servers

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Mail/IMAPClient/.packlist

do-configure:
	@cd ${WRKSRC} && ${ECHO} >.test && \
		${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
