# $NetBSD: Makefile,v 1.2 2001/02/17 18:24:57 wiz Exp $
#

DISTNAME=       IMAP-Admin-1.3.7
PKGNAME=        p5-${DISTNAME}
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
