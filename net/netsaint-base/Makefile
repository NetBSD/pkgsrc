# $NetBSD: Makefile,v 1.2 2001/01/16 16:23:07 rh Exp $
#

DISTNAME=	netsaint-0.0.6
PKGNAME=	${DISTNAME:S/-/-base-/}
CATEGORIES=	net
MASTER_SITES=	http://netsaint.sourceforge.net/download/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.netsaint.org/

DEPENDS+=	gd>1.8.1:../../graphics/gd

.include "Makefile.common"

MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-configure:
	${SED} <${FILESDIR}/netsaint-setup.sh >${WRKDIR}/netsaint-setup.sh \
		-e 's:@@USER@@:${NETSAINT_USER}:g'			\
		-e 's:@@GROUP@@:${NETSAINT_GROUP}:g'
	${SED} -e 's:@@PREFIX@@:${PREFIX}:g' <${PKGDIR}/MESSAGE >${MESSAGE_FILE}

post-install:
	cd ${WRKSRC} && ${MAKE} install-config
	cd ${WRKDIR} && ${INSTALL_SCRIPT} netsaint-setup.sh ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
