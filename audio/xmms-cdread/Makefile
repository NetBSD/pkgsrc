# $NetBSD: Makefile,v 1.12 2025/01/27 20:21:14 rillig Exp $

DISTNAME=		xmms-cdread-0.14a
PKGREVISION=		4
CATEGORIES=		audio
#MASTER_SITES=		ftp://mud.stack.nl/pub/OuterSpace/willem/

MAINTAINER=		cheusov@NetBSD.org
#HOMEPAGE=		ftp://mud.stack.nl/pub/OuterSpace/willem/
COMMENT=		XMMS input plugin that reads audio data from CDs
LICENSE=		gnu-gpl-v2

# The BSD cdrom access code ostensibly for FreeBSD requires:
#   - CDIOREADTOCENTRY ioctl, which NetBSD and OpenBSD don't have
#   - CDIOCREADAUDIO ioctl, which only Dragonfly has
BROKEN_ON_PLATFORM+=	NetBSD-*-* FreeBSD-*-* OpenBSD-*-*
# no cdrom access code
NOT_FOR_PLATFORM=	Interix-*-*
ONLY_FOR_COMPILER=	gcc clang

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

DOC_FILES=		AUTHORS ChangeLog COPYING NEWS README
PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${PKGDOCDIR}

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PKGDOCDIR}
.endfor

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
