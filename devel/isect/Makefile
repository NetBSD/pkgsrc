# $NetBSD: Makefile,v 1.12 2002/08/12 18:17:41 wiz Exp $
#

DISTNAME=	isect-1.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=isectd/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://isectd.sourceforge.net/
COMMENT=	open source middleware daemon

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
PTHREAD_OPTS+=	require

DOCDIR=		${PREFIX}/share/doc/isect
EGDIR=		${PREFIX}/share/examples/isect

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in ${WRKSRC}/doc/*.html; do \
		${INSTALL_DATA} $${file} ${DOCDIR}; \
	done

	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${EGDIR}

	${SED}	-e "s#@PREFIX@#${PREFIX}#g" \
		-e "s#@ECHO@#${ECHO}#g" \
		${FILESDIR}/isect.sh > ${WRKDIR}/isect.sh
	${INSTALL_SCRIPT} ${WRKDIR}/isect.sh ${PREFIX}/etc/rc.d/isect

	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include "../../www/libwww/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
