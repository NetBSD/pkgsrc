# $NetBSD: Makefile,v 1.3 2001/11/22 08:18:25 itojun Exp $
#

DISTNAME=	dlint1.4.0
PKGNAME=	dlint-1.4.0
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
