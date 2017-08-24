# $NetBSD: Makefile,v 1.28 2017/08/24 20:03:36 adam Exp $

PKGREVISION= 1
.include "Makefile.common"

PKGNAME=		${DISTNAME:S/pdns/powerdns/}
COMMENT=		Modern, advanced and high performance nameserver

.include "options.mk"

CONFIGURE_ARGS+=	--with-dynmodules=no
CONFIGURE_ARGS+=	--with-modules="${PDNS_MODULES}"

RCD_SCRIPTS=		pdns
SMF_NAME=		pdns

EGDIR=			${PREFIX}/share/examples/pdns

CONF_FILES+=		${EGDIR}/pdns.conf-dist ${PKG_SYSCONFDIR}/pdns.conf

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	pdns/pdns.conf-dist
SUBST_SED.conf=		-e 's,@PREFIX@,${PREFIX},'
SUBST_SED.conf+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},'

LDFLAGS.SunOS+=		-lsocket -lnsl

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

CHECK_WRKREF_SKIP+=	sbin/pdns_server

.include "../../mk/bsd.pkg.mk"
