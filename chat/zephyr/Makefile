# $NetBSD: Makefile,v 1.1.1.1 2003/09/16 19:41:50 seb Exp $
#

DISTNAME=	zephyr-20010518
PKGREVISION=	1
WRKSRC=		${WRKDIR}/zephyr
CATEGORIES=	chat net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/zephyr/

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://web.mit.edu/olh/Zephyr/index.html
COMMENT=	Project Athena's original Instant Messaging system

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

# N.B. the following assume NetBSD-only. 
CPPFLAGS+=      -I/usr/include/kerberosIV -I/usr/include/krb5
LDFLAGS+=       -lroken -lcrypto -lcom_err -ledit -lcurses
CONFIGURE_ARGS=	--sysconfdir="${PKG_SYSCONFDIR}"
CONFIGURE_ARGS+="--with-krb4"
CONFIGURE_ARGS+="--with-hesiod"
CONFIGURE_ARGS+="--with-ares"

ZEPHYR_DOCDIR=	${PREFIX}/share/doc/zephyr
ZEPHYR_DOCS=	INSTALL NOTES OPERATING README USING

PKG_SYSCONFSUBDIR=	zephyr
OWN_DIRS=		${PKG_SYSCONFDIR}/acl
EGDIR=			${PREFIX}/share/examples/zephyr
CONF_FILES=		${EGDIR}/default.subscriptions \
			${PKG_SYSCONFDIR}/default.subscriptions

RCD_SCRIPTS=		zhm

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${ZEPHYR_DOCDIR}
.for f in ${ZEPHYR_DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${ZEPHYR_DOCDIR}
.endfor
.undef f

.include "../../devel/readline/buildlink2.mk"
.include "../../net/hesiod/buildlink2.mk"
.include "../../net/libares/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
