# $NetBSD: Makefile,v 1.45 2019/07/01 04:08:42 ryoon Exp $

PKGREVISION= 1
.include "Makefile.common"

PKGNAME=	${DISTNAME:S/pdns/powerdns/}
COMMENT=	Modern, advanced and high performance nameserver

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
SUBST_VARS.conf+=	PREFIX PKG_SYSCONFDIR

LDFLAGS.SunOS+=		-lsocket -lnsl

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

.include "../../mk/bsd.pkg.mk"
