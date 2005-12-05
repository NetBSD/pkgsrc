# $NetBSD: Makefile,v 1.10 2005/12/05 20:50:23 rillig Exp $
#

DISTNAME=	dpbox-60000
PKGNAME=	dpbox-6.00.00
CATEGORIES=	ham
MASTER_SITES=	http://home.snafu.de/wahlm/dl8hbs/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://home.snafu.de/wahlm/dl8hbs/dpbox.html
COMMENT=	Multi-Protocol Amateur Packet Radio BBS

WRKSRC=		${WRKDIR}/dpbox-6.00.00/source
USE_TOOLS+=	gmake
MAKEFILE=	Makefile.netbsd

MAKE_ENV+=	prefix=${PREFIX:Q}

.include "../../mk/bsd.prefs.mk"

DPBOX_CONF_DIR=	${PREFIX}/share/dpbox/conf
DPBOX_SPOOL_DIR=/var/spool/dpbox
DEINSTALL_FILE= ${WRKDIR}/DEINSTALL

post-build:
	@cd ${PKGDIR}; \
	${SED} -e 's#@DPBOX_CONF_DIR@#${DPBOX_CONF_DIR}#g' \
	       -e 's#@DPBOX_SPOOL_DIR@#${DPBOX_SPOOL_DIR}#g' \
	       < DEINSTALL > ${WRKDIR}/DEINSTALL; \
	${SED} -e 's#@prefix@#${PREFIX}#g' \
	       < ${FILESDIR}/dpbox.ini > ${WRKDIR}/dpbox-6.00.00/dpbox.ini

.include "../../mk/bsd.pkg.mk"
