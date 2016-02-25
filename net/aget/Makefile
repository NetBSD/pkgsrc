# $NetBSD: Makefile,v 1.15 2016/02/25 16:20:50 jperkin Exp $
#

DISTNAME=	aget-0.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.enderunix.org/aget/

MAINTAINER=	eeg@e3labs.ath.cx
HOMEPAGE=	http://www.enderunix.org/aget/
COMMENT=	Multithreaded HTTP download accelerator

NO_CONFIGURE=	yes

SUBST_CLASSES+=		options
SUBST_MESSAGE.options=	Fixing build options.
SUBST_STAGE.options=	post-patch
SUBST_FILES.options=	Makefile Makefile.Solaris
SUBST_SED.options=	-e 's,CFLAGS =,\#CFLAGS =,'
SUBST_SED.options+=	-e 's,LDFLAGS =,\#LDFLAGS =,'
SUBST_SED.options+=	-e 's,CC =,\#CC =,'

PTHREAD_OPTS+=		require
LDFLAGS+=		${PTHREAD_LIBS}
PTHREAD_AUTO_VARS=	yes

CFLAGS.SunOS+=	-DSOLARIS
LDFLAGS.SunOS+=	-lsocket -lnsl -lresolv

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aget ${DESTDIR}${PREFIX}/bin/aget

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
