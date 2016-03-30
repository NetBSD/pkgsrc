# $NetBSD: Makefile,v 1.16 2016/03/30 08:33:18 jperkin Exp $
#

DISTNAME=	dlint1.4.0
PKGNAME=	dlint-1.4.0
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.domtools.com/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.domtools.com/
COMMENT=	Internet Domain Name System (DNS) error checking utility

USE_TOOLS+=	perl:run
NO_BUILD=	YES

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

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
