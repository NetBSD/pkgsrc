# $NetBSD: Makefile,v 1.1 2012/08/26 14:06:19 wiz Exp $
#

DISTNAME=	irssi-xmpp-0.52
CATEGORIES=	chat
MASTER_SITES=	http://cybione.org/~irssi-xmpp/files/
DISTFILES=	${DISTNAME}.tar.gz ${IRSSI_DISTFILE}

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://cybione.org/~irssi-xmpp/
COMMENT=	Irssi plugin to connect to the Jabber network
LICENSE=	gnu-gpl-v2

DEPENDS+=	irssi>=${IRSSI_VERSION}:../../chat/irssi

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"
.include "../../chat/irssi/Makefile.common"

MAKE_JOBS_SAFE=	no
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/${IRSSI_DISTNAME}/${DISTNAME}

MAKE_ENV+=	IRSSI_INCLUDE="${WRKDIR}/${IRSSI_DISTNAME}"

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing doc-install Makefile target.
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e '/docs/s/install/install -m 644/'

post-extract:
	${MV} ${WRKDIR}/${DISTNAME} ${WRKDIR}/${IRSSI_DISTNAME}
	${CP} ${IRSSI_CONFIG_H} ${WRKSRC}/src/config.h

.include "../../chat/loudmouth/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
