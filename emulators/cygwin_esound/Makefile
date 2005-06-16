# $NetBSD: Makefile,v 1.4 2005/06/16 06:57:50 jlam Exp $
#

DISTNAME=		esound-0.2.35-1
PKGNAME=		${DISTNAME:S/-/!/:S/-/./g:S/!/-/:S/^/cygwin_/}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_CYGWIN:=release/esound/} \
			${MASTER_SITE_CYGWIN:=release/esound/libesound0/} \
			${MASTER_SITE_CYGWIN:=release/audiofile/libaudiofile0/}
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			libesound0-0.2.35-1.tar.bz2 \
			libaudiofile0-0.2.6-2.tar.bz2

MAINTAINER=		tv@duh.org
COMMENT=		Enlightened sound daemon (daemon only) for Cygwin/Interix

ONLY_FOR_PLATFORM=	Interix-*-*

DIST_SUBDIR=		cygwin
WRKSRC=			${WRKDIR}
USE_PKGINSTALL=		yes

RCD_SCRIPTS=		cygwin_esd
INSTALLATION_DIRS=	bin emul/cygwin/bin

do-build: # nothing

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/cygaudiofile-0.dll ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/cygesd-0.dll ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/esd.exe ${PREFIX}/emul/cygwin/bin/

.include "../../emulators/cygwin_lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
