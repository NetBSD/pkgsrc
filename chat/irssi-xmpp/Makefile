# $NetBSD: Makefile,v 1.13 2019/06/29 09:29:43 nia Exp $
#

DISTNAME=	irssi-xmpp-0.53
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	http://cybione.org/~irssi-xmpp/files/
DISTFILES=	${DISTNAME}.tar.gz ${IRSSI_DISTFILE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cybione.org/~irssi-xmpp/
COMMENT=	Irssi plugin to connect to the Jabber network
LICENSE=	gnu-gpl-v2

DEPENDS+=	irssi>=${IRSSI_VERSION}:../../chat/irssi

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

SUBST_CLASSES+=		configmk
SUBST_STAGE.configmk=	pre-build
SUBST_MESSAGE.configmk=	Fixing CFLAGS and LDFLAGS to be user-settable.
SUBST_FILES.configmk=	config.mk
SUBST_SED.configmk+=	-e 's/^CFLAGS =/CFLAGS +=/'
SUBST_SED.configmk+=	-e 's/^LDFLAGS =/LDFLAGS +=/'

SUBST_CLASSES.Darwin+=	osxmk
SUBST_STAGE.osxmk=	pre-build
SUBST_FILES.osxmk=	config.mk
SUBST_SED.osxmk=	-e 's,-shared,-dynamiclib -undefined dynamic_lookup,'

CFLAGS.SunOS+=	-D__BEGIN_DECLS= -D__END_DECLS=

post-extract:
	${MV} ${WRKDIR}/${DISTNAME} ${WRKDIR}/${IRSSI_DISTNAME}
	${CP} ${IRSSI_CONFIG_H} ${WRKSRC}/src/config.h

.include "../../chat/loudmouth/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
