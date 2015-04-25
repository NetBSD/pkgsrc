# $NetBSD: Makefile,v 1.9 2015/04/25 14:20:25 tnn Exp $
#

DISTNAME=		xmms-cdread-0.14a
PKGREVISION=		4
CATEGORIES=		audio
MASTER_SITES=		ftp://mud.stack.nl/pub/OuterSpace/willem/

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		ftp://mud.stack.nl/pub/OuterSpace/willem/
COMMENT=		XMMS input plugin that reads audio data from CDs

# no cdrom access code
NOT_FOR_PLATFORM=	Interix-*-*

# The BSD cdrom access code ostensibly for FreeBSD requires:
#   - CDIOREADTOCENTRY ioctl, which NetBSD and OpenBSD don't have
#   - CDIOCREADAUDIO ioctl, which only Dragonfly has
BROKEN_ON_PLATFORM+=	NetBSD-*-* FreeBSD-*-* OpenBSD-*-*
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
