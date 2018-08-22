# $NetBSD: Makefile,v 1.33 2018/08/22 09:43:11 wiz Exp $

DISTNAME=		lbdb_0.35.1
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		6
CATEGORIES=		databases
MASTER_SITES=		http://www.spinnaker.de/debian/

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.spinnaker.de/lbdb/
COMMENT=		The little brother's database

DEPENDS+=		p5-perl-ldap>=0.20:../../databases/p5-perl-ldap

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run

GNU_CONFIGURE_LIBSUBDIR=../libexec/lbdb
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-lbdb_dotlock
CONFIGURE_ARGS+=	--without-getent
CONFIGURE_ARGS+=	--without-evolution-addressbook-export
CONFIGURE_ARGS+=	--without-pgp
CONFIGURE_ARGS+=	--without-pgpk

CONFIGURE_ENV+=		SH=${TOOLS_SH:Q}
CONFIGURE_ENV+=		AWK=${TOOLS_AWK:Q}
CONFIGURE_ENV+=		ac_cv_path_TAC=NONE

.include "options.mk"

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

EGDIR=			${PREFIX}/share/examples/lbdb
CONF_FILES+=		${EGDIR}/lbdb.rc ${PKG_SYSCONFDIR}/lbdb.rc
CONF_FILES+=		${EGDIR}/lbdb_ldap.rc ${PKG_SYSCONFDIR}/lbdb_ldap.rc

PLIST_VARS+=		finger
.if ${OPSYS} != "SunOS" || exists(/usr/bin/finger)
PLIST.finger=		yes
.endif

PLIST_VARS+=		yp
.if ${OPSYS} != "Interix"
PLIST.yp=		yes
.endif

INSTALL_MAKE_FLAGS+=	install_prefix=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
