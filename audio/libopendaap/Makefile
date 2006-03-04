# $NetBSD: Makefile,v 1.10 2006/03/04 21:28:56 jlam Exp $

DISTNAME=	libopendaap-0.4.0
CATEGORIES=	audio
MASTER_SITES=	http://craz.net/programs/itunes/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://craz.net/programs/itunes/libopendaap.html
COMMENT=	DAAP client library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_TOOLS+=		pkg-config

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	opendaap.pc.in
SUBST_SED.pthread=	-e 's|@@PTHREAD@@|${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}|'

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
