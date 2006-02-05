# $NetBSD: Makefile,v 1.32 2006/02/05 23:08:44 joerg Exp $
#

DISTNAME=	isect-1.6.2
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=isectd/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://isectd.sourceforge.net/
COMMENT=	Open source middleware daemon

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PTHREAD_OPTS+=		require
INFO_FILES=		isect.info

RCD_SCRIPTS=	isect

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

DOCDIR=		${PREFIX}/share/doc/isect
EGDIR=		${PREFIX}/share/examples/isect

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in ${WRKSRC}/doc/*.html; do \
		${INSTALL_DATA} $${file} ${DOCDIR}; \
	done

	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${EGDIR}

.include "../../www/libwww/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
