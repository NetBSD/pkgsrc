# $NetBSD: Makefile,v 1.30 2017/06/05 14:22:17 ryoon Exp $
#

DISTNAME=		ices-${ICES_VERSION}
PKGNAME=		ices-mp3-${ICES_VERSION}
PKGREVISION=		14
ICES_VERSION=		0.4
CATEGORIES=		audio
MASTER_SITES=		http://svn.xiph.org/releases/ices/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.icecast.org/ices.php
COMMENT=		Source client for a streaming server
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		automake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

BUILD_DEFS+=		ICES_USE_PERL ICES_USE_PYTHON
ICES_USE_PERL?=		NO
ICES_USE_PYTHON?=	NO

CONFIGURE_ARGS+=	--program-suffix=-mp3
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-docdir=${DOCDIR:Q}
CONFIGURE_ARGS+=	--with-moddir=${MODDIR:Q}

PKG_SYSCONFSUBDIR=	icecast
#RCD_SCRIPTS=		${PKGBASE}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MODDIR=			${PREFIX}/share/${PKGBASE}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

pre-configure:
	cd ${WRKSRC} && autoreconf --force -i

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ices \
		${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_MAN} ${WRKSRC}/doc/ices.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PKGBASE}.1
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/icesmanual.html ${DESTDIR}${DOCDIR}
	for i in AUTHORS BUGS COPYING NEWS README README.playlist TODO ; \
	do \
	    ${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${DOCDIR}/$$i ; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	for i in ices.conf.dist ices.pm.dist ices.py.dist ; \
	do \
	    ${INSTALL_DATA} ${WRKSRC}/conf/$$i ${DESTDIR}${EGDIR}/$$i ; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${MODDIR}

# does not support flac-1.1.3 API
#.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libshout/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.if defined(ICES_USE_PERL) && (${ICES_USE_PERL} == "YES")
.include "../../lang/perl5/buildlink3.mk"
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
.endif
.if defined(ICES_USE_PYTHON) && (${ICES_USE_PYTHON} == "YES")
.include "../../lang/python/application.mk"
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN:Q}
.endif
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
