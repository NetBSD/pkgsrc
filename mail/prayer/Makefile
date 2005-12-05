# $NetBSD: Makefile,v 1.23 2005/12/05 20:50:35 rillig Exp $
#

DISTNAME=	prayer-1.0.12
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/prayer/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www-uxsup.csx.cam.ac.uk/~dpc22/prayer/
COMMENT=	Small, fast, web mail interface

USE_PKGINSTALL=	yes
USE_TOOLS+=	gmake perl
PRAYER_USER=	prayer
PRAYER_GROUP=	prayer
PKG_GROUPS=	${PRAYER_GROUP}
PKG_USERS=	${PRAYER_USER}:${PRAYER_GROUP}

MAKE_ENV+=	EGDIR=${EGDIR:Q}
MAKE_ENV+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
MAKE_ENV+=	BUILDLINK_PREFIX.db4="${BUILDLINK_PREFIX.db4}"
MAKE_ENV+=	BUILDLINK_PREFIX.imap-uw="${BUILDLINK_PREFIX.imap-uw}"
MAKE_ENV+=	SSLCERTS=${SSLCERTS:Q}

PKG_SYSCONFSUBDIR=	prayer
EGDIR=			${PREFIX}/share/examples/prayer

RCD_SCRIPTS=		prayer

CONF_FILES=	${EGDIR}/prayer.cf ${PKG_SYSCONFDIR}/prayer.cf
CONF_FILES+=	${EGDIR}/prayer-accountd.cf ${PKG_SYSCONFDIR}/prayer-accountd.cf
CONF_FILES+=	${EGDIR}/motd.html ${PKG_SYSCONFDIR}/motd.html
CONF_FILES+=	${EGDIR}/welcome.html ${PKG_SYSCONFDIR}/welcome.html

VAR_PREFIX=	${VARBASE}/spool/prayer

OWN_DIRS+=	${EGDIR}
OWN_DIRS_PERMS+=${VAR_PREFIX} ${PRAYER_USER} ${PRAYER_GROUP} 0750

FILES_SUBST+=	OPSYS=${OPSYS:Q}
FILES_SUBST+=	VAR_PREFIX=${VAR_PREFIX:Q}

post-patch:
	${FIND} ${WRKSRC} -name CVS -type d -print | ${SORT} -r | \
		${XARGS} ${RM} -r

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mail/imap-uw/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
