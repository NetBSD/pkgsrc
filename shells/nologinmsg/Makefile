# $NetBSD: Makefile,v 1.8 2006/02/15 20:08:41 rillig Exp $

DISTNAME=	nologinmsg-1.0
CATEGORIES=	shells sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	cjep@NetBSD.org
#HOMEPAGE=
COMMENT=	More functional native binary replacement for /sbin/nologin

SUBST_CLASSES+=		nlm
SUBST_STAGE.nlm=	pre-configure
SUBST_FILES.nlm=	nologinmsg.8 pathnames.h
SUBST_SED.nlm=		-e 's|/usr/local/etc|${PKG_SYSCONFDIR}|g'

LIBS.Linux+=	-lnbcompat
LIBS.IRIX+=	-lnbcompat
MAKE_FLAGS+=	LDADD=${LIBS:M*:Q}
MAKE_FLAGS+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q}
MAKE_FLAGS+=	MANOWN=${MANOWN:Q} MANGRP=${MANGRP:Q}

.include "../../mk/bsd.prefs.mk"
# XXX: ${OPSYS} != "NetBSD" ?
.if ${OPSYS} == "Linux" || ${OPSYS} == "IRIX" || ${OPSYS} == "Interix"
MAKE_FLAGS+=	NOMAN=YES
CFLAGS+=	-D__LIBNBCOMPAT
.  include "../../pkgtools/libnbcompat/buildlink3.mk"
.endif

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
