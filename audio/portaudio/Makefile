# $NetBSD: Makefile,v 1.20 2012/10/02 23:48:04 asau Exp $

DISTNAME=	portaudio_v18_1
PKGNAME=	portaudio-18.1
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.portaudio.com/
COMMENT=	Portable cross-platform Audio API

NOT_FOR_PLATFORM=	Interix-*-*

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CFLAGS.Darwin=		-Ipablio

INSTALLATION_DIRS+=	lib include

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
RT_LIB_SCHED=		-lrt
.else
RT_LIB_SCHED=		# empty
.endif
MAKE_ENV+=		RT_LIB_SCHED=${RT_LIB_SCHED}

pre-configure:
	${CHMOD} 755 ${WRKSRC:Q}/configure

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
