# $NetBSD: Makefile,v 1.2 2001/02/17 18:18:48 wiz Exp $
#

DISTNAME=	dlint1.3.2
PKGNAME=	dlint-1.3.2
CATEGORIES=	net
MASTER_SITES=	http://www.domtools.com/pub/

MAINTAINER=	hubertf@netbsd.org
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
