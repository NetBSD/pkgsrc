# $NetBSD: Makefile,v 1.1.1.1 2004/04/24 18:08:13 kim Exp $
#

DISTNAME=		ices-${ICES_VERSION}
PKGNAME=		ices-mp3-${ICES_VERSION}
ICES_VERSION=		0.3
CATEGORIES=		audio
MASTER_SITES=		http://www.icecast.org/files/ices/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.icecast.org/ices.php
COMMENT=		Source client for a streaming server

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

BUILD_DEFS+=		ICES_USE_PERL ICES_USE_PYTHON
ICES_USE_PERL?=		NO
ICES_USE_PYTHON?=	NO

CONFIGURE_ARGS+=	--program-suffix=-mp3
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-docdir=${DOCDIR}
CONFIGURE_ARGS+=	--with-moddir=${MODDIR}

PKG_SYSCONFSUBDIR=	icecast
#RCD_SCRIPTS=		${PKGBASE}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MODDIR=			${PREFIX}/share/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ices ${PREFIX}/bin/${PKGBASE}
	${INSTALL_MAN} ${WRKSRC}/doc/ices.1 ${PREFIX}/man/man1/${PKGBASE}.1
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/icesmanual.html ${DOCDIR}
	for i in AUTHORS BUGS COPYING NEWS README README.playlist TODO ; \
	do \
	    ${INSTALL_DATA} ${WRKSRC}/$$i ${DOCDIR}/$$i ; \
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	for i in ices.conf.dist ices.pm.dist ices.py.dist ; \
	do \
	    ${INSTALL_DATA} ${WRKSRC}/conf/$$i ${EGDIR}/$$i ; \
	done
	${INSTALL_DATA_DIR} ${MODDIR}

.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libshout/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.if defined(ICES_USE_PERL) && (${ICES_USE_PERL} == "YES")
.include "../../lang/libperl/buildlink3.mk"
.endif
.if defined(ICES_USE_PYTHON) && (${ICES_USE_PYTHON} == "YES")
.include "../../lang/python/application.mk"
.endif
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
