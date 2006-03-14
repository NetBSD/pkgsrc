# $NetBSD: Makefile,v 1.12 2006/03/14 01:14:29 jlam Exp $
#

DISTNAME=	dpbox-60000
PKGNAME=	dpbox-6.00.00
PKGREVISION=	1
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
FILES_SUBST+=	DPBOX_CONF_DIR=${DPBOX_CONF_DIR}			\
		DPBOX_SPOOL_DIR=${DPBOX_SPOOL_DIR}
DEINSTALL_SRC=	${PKGDIR}/DEINSTALL
INSTALL_SRC=	# empty

post-build:
	${SED} -e 's#@prefix@#${PREFIX}#g' \
		< ${FILESDIR}/dpbox.ini > ${WRKDIR}/dpbox-6.00.00/dpbox.ini

.include "../../mk/bsd.pkg.mk"
