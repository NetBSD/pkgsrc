# $NetBSD: Makefile,v 1.6 2023/07/09 08:12:25 nia Exp $

DISTNAME=	jack_umidi-1.1.2
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=hselasky/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hselasky/jack_umidi
COMMENT=	Raw/BSD/OSS MIDI to JACK MIDI daemon
LICENSE=	2-clause-bsd

MAKE_FLAGS+=	HAVE_MAN=yes
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

USE_BSD_MAKEFILE=	yes

ONLY_FOR_PLATFORM+=	FreeBSD-*-* NetBSD-*-* OpenBSD-*-*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	jack_umidi.c
SUBST_FILES.paths+=	jack_umidi.8
SUBST_SED.paths=	-e 's,/dev/umidi0.0,/dev/rmidi0,g'
.endif

INSTALLATION_DIRS+=	sbin
INSTALLATION_DIRS+=	${PKGMANDIR}/man8

.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
