# $NetBSD: Makefile,v 1.17 2004/10/03 00:12:54 tv Exp $
#

DISTNAME=	prayer-1.0.8
PKGREVISION=	4
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/prayer/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www-uxsup.csx.cam.ac.uk/~dpc22/prayer/
COMMENT=	Small, fast, web mail interface

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
USE_GNU_TOOLS+=	make
USE_PERL5=	build
PRAYER_USER=	prayer
PRAYER_GROUP=	prayer
PKG_GROUPS=	${PRAYER_GROUP}
PKG_USERS=	${PRAYER_USER}:${PRAYER_GROUP}

MAKE_ENV+=	EGDIR="${EGDIR}"
MAKE_ENV+=	PKG_SYSCONFDIR="${PKG_SYSCONFDIR}"
MAKE_ENV+=	BUILDLINK_PREFIX.db4="${BUILDLINK_PREFIX.db4}"
MAKE_ENV+=	BUILDLINK_PREFIX.imap-uw="${BUILDLINK_PREFIX.imap-uw}"
MAKE_ENV+=	SSLCERTS="${SSLCERTS}"

PKG_SYSCONFSUBDIR=	prayer
EGDIR=			${PREFIX}/share/examples/prayer

RCD_SCRIPTS=		prayer
RCD_SCRIPT_SRC.prayer=	${FILESDIR}/prayer.rc

CONF_FILES=	${EGDIR}/prayer.cf ${PKG_SYSCONFDIR}/prayer.cf
CONF_FILES+=	${EGDIR}/prayer-accountd.cf ${PKG_SYSCONFDIR}/prayer-accountd.cf
CONF_FILES+=	${EGDIR}/motd.html ${PKG_SYSCONFDIR}/motd.html
CONF_FILES+=	${EGDIR}/welcome.html ${PKG_SYSCONFDIR}/welcome.html

VAR_PREFIX=	/var/spool/prayer

OWN_DIRS+=	${EGDIR}
OWN_DIRS_PERMS+=${VAR_PREFIX} ${PRAYER_USER} ${PRAYER_GROUP} 0750

FILES_SUBST+=	OPSYS="${OPSYS}"
FILES_SUBST+=	VAR_PREFIX="${VAR_PREFIX}"

post-patch:
	${FIND} ${WRKSRC} -name CVS -type d -print | ${SORT} -r | \
		${XARGS} ${RM} -r

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mail/imap-uw/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
