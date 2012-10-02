# $NetBSD: Makefile,v 1.8 2012/10/02 12:20:47 jperkin Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGNAME=		${DISTNAME:S/pdns/powerdns/}
PKGREVISION=		2
COMMENT=		Modern, advanced and high performance nameserver

CONFIGURE_ARGS+=	--with-modules="geo"
CONFIGURE_ARGS+=	--with-dynmodules="pipe"

RCD_SCRIPTS=		pdns

EGDIR=			${PREFIX}/share/examples/pdns
MAKE_ENV+=		EGDIR=${EGDIR}

CONF_FILES+=		${EGDIR}/pdns.conf-dist ${PKG_SYSCONFDIR}/pdns.conf

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	pdns/pdns.conf-dist
SUBST_SED.conf=		-e 's,@PREFIX@,${PREFIX},'
SUBST_SED.conf+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},'

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
