# $NetBSD: Makefile,v 1.7 2002/01/31 14:20:05 martti Exp $
#

DISTNAME=       IMAP-Admin-1.6.1
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5iad
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IMAP/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module for administration of RFC-2060 IMAP servers

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IMAP/Admin/.packlist

do-configure:
	@cd ${WRKSRC} && ${TOUCH} ${TOUCH_ARGS} .test && \
		${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
