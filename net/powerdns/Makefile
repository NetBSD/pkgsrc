# $NetBSD: Makefile,v 1.12 2015/04/17 15:53:14 adam Exp $

PKGREVISION= 2
.include "Makefile.common"

PKGNAME=		${DISTNAME:S/pdns/powerdns/}
COMMENT=		Modern, advanced and high performance nameserver

.include "options.mk"

CONFIGURE_ARGS+=	--with-modules="geo"
CONFIGURE_ARGS+=	--with-dynmodules="${PDNS_MODULES}"

RCD_SCRIPTS=		pdns
SMF_NAME=		pdns

EGDIR=			${PREFIX}/share/examples/pdns
MAKE_ENV+=		EGDIR=${EGDIR}

CONF_FILES+=		${EGDIR}/pdns.conf-dist ${PKG_SYSCONFDIR}/pdns.conf

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	pdns/pdns.conf-dist
SUBST_SED.conf=		-e 's,@PREFIX@,${PREFIX},'
SUBST_SED.conf+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},'

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
