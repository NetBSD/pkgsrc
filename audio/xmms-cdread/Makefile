# $NetBSD: Makefile,v 1.1.1.1 2011/03/06 16:46:04 wiz Exp $
#

DISTNAME=		xmms-cdread-0.14a
CATEGORIES=		audio
MASTER_SITES=		ftp://mud.stack.nl/pub/OuterSpace/willem/

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		ftp://mud.stack.nl/pub/OuterSpace/willem/
COMMENT=		XMMS input plugin that reads audio data from CDs

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	Interix-*-* NetBSD-*-*
ONLY_FOR_COMPILER=	gcc

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
