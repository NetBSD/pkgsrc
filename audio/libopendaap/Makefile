# $NetBSD: Makefile,v 1.12 2008/07/14 12:55:57 joerg Exp $

DISTNAME=	libopendaap-0.4.0
CATEGORIES=	audio
MASTER_SITES=	http://craz.net/programs/itunes/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://craz.net/programs/itunes/libopendaap.html
COMMENT=	DAAP client library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	opendaap.pc.in
SUBST_SED.pthread=	-e 's|@@PTHREAD@@|${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}|'

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
