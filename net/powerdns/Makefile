# $NetBSD: Makefile,v 1.54 2020/06/02 08:24:34 adam Exp $

PKGREVISION= 4
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

LDFLAGS.SunOS+=		-lsocket -lnsl

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

.include "../../mk/bsd.pkg.mk"
