# $NetBSD: Makefile,v 1.16 2009/05/20 00:58:08 wiz Exp $
#

DISTNAME=	zephyr-20010518
PKGREVISION=	7
CATEGORIES=	chat net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/zephyr/

MAINTAINER=	sommerfeld@NetBSD.org
HOMEPAGE=	http://web.mit.edu/olh/Zephyr/index.html
COMMENT=	Project Athena's original Instant Messaging system

WRKSRC=		${WRKDIR}/zephyr
GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-I${BUILDLINK_PREFIX.kth-krb4}/include/kerberosIV
CPPFLAGS.NetBSD+=	-I${BUILDLINK_PREFIX.kth-krb4}/include/kerberosIV/ss
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-krb4
CONFIGURE_ARGS+=	--with-hesiod
CONFIGURE_ARGS+=	--with-ares

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
	${INSTALL_DATA} ${WRKSRC}/${f} ${ZEPHYR_DOCDIR}
.endfor

.include "../../devel/readline/buildlink3.mk"
.include "../../net/hesiod/buildlink3.mk"
.include "../../net/libares/buildlink3.mk"
.include "../../security/kth-krb4/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
