# $NetBSD: Makefile,v 1.1.1.1 2001/11/28 12:28:23 martti Exp $
#

DISTNAME=	Net-ICQ2000-0.2.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	chat perl5
MASTER_SITES=	http://gonzo.kiev.ua/projects/vicq/

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://icq2000.phase3solutions.com/
COMMENT=	perl5 modules for the ICQv7 protocol realisation

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Net/ICQ2000/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
