# $NetBSD: Makefile,v 1.5 2023/12/16 15:46:44 zafer Exp $
#

PKGNAME=	pluged-0.1
DISTNAME=	pluged
CATEGORIES=	sysutils
MASTER_SITES=	https://www.aydogan.net/distfiles/sysutils/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gnux.info/
COMMENT=	USB plug/unplug monitoring daemon
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	lex

BUILDLINK_TRANSFORM=	rm:-Werror

EGDIR=		${PREFIX}/share/examples/pluged
RCDDIR=		${PREFIX}/share/examples/rc.d
CONF_FILES+=	${EGDIR}/pluged.conf ${PREFIX}/etc/pluged.conf

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	rcd

.if ${INIT_SYSTEM} == "rc.d"
PLIST.rcd=	yes
.endif

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}/${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${DESTDIR}/${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/pluged ${DESTDIR}/${PREFIX}/sbin/pluged
	${INSTALL_DATA} ${WRKSRC}/pluged.conf ${DESTDIR}/${EGDIR}/pluged.conf
.if ${INIT_SYSTEM} == "rc.d"
	${INSTALL_DATA_DIR} ${DESTDIR}/${RCDDIR}
	${INSTALL_DATA} ${WRKSRC}/rc.d/pluged ${DESTDIR}/${RCDDIR}/pluged
.endif

.include "../../mk/bsd.pkg.mk"
