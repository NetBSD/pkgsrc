# $NetBSD: Makefile,v 1.5 2001/11/26 06:50:04 jlam Exp $
#

DISTNAME=       Mail-IMAPClient-1.07
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5mic
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module for talking to RFC-2060 IMAP servers

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/IMAPClient/.packlist

do-configure:
	@cd ${WRKSRC} && ${TOUCH} ${TOUCH_ARGS} .test && \
		${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
