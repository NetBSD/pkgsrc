# $NetBSD: Makefile,v 1.15 2003/01/28 22:03:15 jlam Exp $
#

DISTNAME=	isect-1.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=isectd/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://isectd.sourceforge.net/
COMMENT=	open source middleware daemon

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
PTHREAD_OPTS+=	require

RCD_SCRIPTS=	isect

DOCDIR=		${PREFIX}/share/doc/isect
EGDIR=		${PREFIX}/share/examples/isect

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in ${WRKSRC}/doc/*.html; do \
		${INSTALL_DATA} $${file} ${DOCDIR}; \
	done

	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${EGDIR}

.include "../../www/libwww/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
