# $NetBSD: Makefile,v 1.4 2001/10/18 15:20:26 veego Exp $
#

DISTNAME=       IMAP-Admin-1.4.3
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5iad
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IMAP/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module for administration of RFC-2060 IMAP servers

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/IMAP/Admin/.packlist

do-configure:
	@cd ${WRKSRC} && ${ECHO} >.test && \
		${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
