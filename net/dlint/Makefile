# $NetBSD: Makefile,v 1.5 2005/02/21 20:26:13 hubertf Exp $
#

DISTNAME=	dlint1.4.0
PKGNAME=	dlint-1.4.0
CATEGORIES=	net
MASTER_SITES=	http://www.domtools.com/pub/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.domtools.com/dns/
COMMENT=	Internet Domain Name System (DNS) error checking utility

USE_PERL5=	YES
NO_BUILD=	YES

do-configure:
	cd ${WRKSRC} ; \
	${MV} digparse digparse.BAK ; \
	${SED} \
		-e '/usr.bin.perl/s|/usr|${PREFIX}|g' \
		<digparse.BAK >digparse ; \
	${MV} dlint dlint.BAK ; \
	${SED} \
		-e 's|/usr/local|${PREFIX}|g' \
		<dlint.BAK >dlint

.include "../../mk/bsd.pkg.mk"
