# $NetBSD: Makefile,v 1.13 2013/04/06 21:07:34 rodent Exp $
#

DISTNAME=	aget-0.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.enderunix.org/aget/

MAINTAINER=	eeg@e3labs.ath.cx
HOMEPAGE=	http://www.enderunix.org/aget/
COMMENT=	Multithreaded HTTP download accelerator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

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

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DSOLARIS
LDFLAGS+=	-lsocket -lnsl -lresolv
.endif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aget ${DESTDIR}${PREFIX}/bin/aget

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
