# $NetBSD: Makefile,v 1.1.1.1 2000/10/16 09:11:35 rh Exp $
#

DISTNAME=       IMAP-Admin-1.3.7
PKGNAME=        p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IMAP/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/IMAP/Admin/.packlist

do-configure:
	@cd ${WRKSRC} && ${ECHO} >.test && \
		${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
