# $NetBSD: Makefile,v 1.10 2003/11/12 03:39:41 jschauma Exp $
#

DISTNAME=	prayer-1.0.8
PKGREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/prayer/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www-uxsup.csx.cam.ac.uk/~dpc22/prayer/
COMMENT=	Small, fast, web mail interface

PKG_GROUPS=	prayer

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_GMAKE=	YES
USE_PERL5=	build

MAKE_ENV+=	EGDIR="${EGDIR}"
MAKE_ENV+=	PKG_SYSCONFDIR="${PKG_SYSCONFDIR}"
MAKE_ENV+=	BUILDLINK_PREFIX.db4="${BUILDLINK_PREFIX.db4}"
MAKE_ENV+=	BUILDLINK_PREFIX.imap-uw="${BUILDLINK_PREFIX.imap-uw}"

PKG_SYSCONFSUBDIR=	prayer
EGDIR=		${PREFIX}/share/examples/prayer

CONF_FILES=	${EGDIR}/prayer.cf ${PKG_SYSCONFDIR}/prayer.cf
CONF_FILES+=	${EGDIR}/prayer-accountd.cf ${PKG_SYSCONFDIR}/prayer-accountd.cf
CONF_FILES+=	${EGDIR}/motd.html ${PKG_SYSCONFDIR}/motd.html
CONF_FILES+=	${EGDIR}/welcome.html ${PKG_SYSCONFDIR}/welcome.html

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

post-install:
	${FIND} -d ${PREFIX}/share/prayer -name CVS -type d -exec ${RM} -r {} \;

.include "../../databases/db4/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mail/imap-uw/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
