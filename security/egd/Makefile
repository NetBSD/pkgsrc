# $NetBSD: Makefile,v 1.2 2001/02/17 17:49:43 wiz Exp $
#

DISTNAME=	egd-0.8
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.lothar.com/linux/ \
		http://www.lothar.com/pub/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.lothar.com/tech/crypto/
COMMENT=	EGD: Entropy Gathering Daemon

DEPENDS+=	p5-SHA-*:../../security/p5-SHA

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/egd/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
