# $NetBSD: Makefile,v 1.62 2017/08/01 16:47:37 wiz Exp $

DISTNAME=	audiofile-0.3.6
PKGNAME=	lib${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.68k.org/~michael/audiofile/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://andromeda.68k.org/~michael/audiofile/
COMMENT=	Sound library for SGI audio file
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	audiofile.pc.in

DOCDIR=			${PREFIX}/share/doc/libaudiofile

INSTALLATION_DIRS=	${DOCDIR}

post-build:
	cd ${WRKSRC}/docs && \
	for i in af*3; do \
		if grep -q '^.so ' $$i >/dev/null; then \
			sed -e "s_.so _.so man3/_" $$i > $$i.new && mv $$i.new $$i; \
		fi; \
	done

post-install:
	cd ${WRKSRC}/docs && ${INSTALL_DATA} af* sf* ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
