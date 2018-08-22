# $NetBSD: Makefile,v 1.19 2018/08/22 09:45:47 wiz Exp $
#

DISTNAME=	whohas-0.29
PKGREVISION=	7
CATEGORIES=	misc
MASTER_SITES=	http://www.philippwesche.org/200811/whohas/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.philippwesche.org/200811/whohas/intro.html
COMMENT=	Query several packaging systems for a program
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run

REPLACE_PERL=	program/whohas

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/de/man1 \
			share/doc/whohas

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/program/whohas ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usr/share/man/man1/whohas.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/usr/share/man/de/man1/whohas.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/de/man1
	${INSTALL_DATA} ${WRKSRC}/intro* \
		${DESTDIR}${PREFIX}/share/doc/whohas

.include "../../mk/bsd.pkg.mk"
