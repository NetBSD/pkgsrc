# $NetBSD: Makefile,v 1.8 2006/03/04 21:30:18 jlam Exp $
#

DISTNAME=	dlint1.4.0
PKGNAME=	dlint-1.4.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.domtools.com/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.domtools.com/dns/
COMMENT=	Internet Domain Name System (DNS) error checking utility

USE_TOOLS+=	perl:run
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
