# $NetBSD: Makefile,v 1.38 2023/12/29 01:20:21 zafer Exp $

DISTNAME=	i2cbd-2.0_BETA5
PKGREVISION=	6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITES+=	https://www.draga.com/~jwise/i2cb/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.draga.com/~jwise/i2cb/
COMMENT=	Next generation Internet Citizens Band chat server

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		ICBD_OWNER
ICBD_OWNER?=		${REAL_ROOT_USER}
PKG_USERS_VARS+=	ICBD_OWNER
PLIST_SUBST+=		ICBD_OWNER=${ICBD_OWNER:Q}

PKG_SYSCONFSUBDIR=	icbd
EGDIR=			${PREFIX}/share/examples/i2cbd
EGFILES=		motd icbd_help icbd.deny news.1
CONF_FILES_PERMS=	# empty
.for f in ${EGFILES}
CONF_FILES_PERMS+=	${EGDIR}/${f:Q} ${PKG_SYSCONFDIR}/${f:Q} \
			${ICBD_OWNER} ${REAL_ROOT_GROUP} 644
.endfor
CONF_FILES_PERMS+=	/dev/null /var/log/icbd.log \
			${ICBD_OWNER} ${REAL_ROOT_GROUP} 644
RCD_SCRIPTS=		icbd
RCD_SCRIPT_SRC.icbd=	${WRKSRC}/etc/icbd.sh
INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/examples/i2cbd \
			share/examples/rc.d

INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/sbin \
			MAN8DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

post-extract:
	-${RM} -f ${WRKSRC}/*/.depend

post-install:
.for f in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${DESTDIR}${EGDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
