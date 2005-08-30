# $NetBSD: Makefile,v 1.4 2005/08/30 16:14:53 tonio Exp $

DISTNAME=		${PKGNAME:S/-/_/}
PKGNAME=		lbdb-0.30
CATEGORIES=		databases
MASTER_SITES=		http://www.spinnaker.de/debian/

MAINTAINER=		reilles@loria.fr
HOMEPAGE=		http://www.spinnaker.de/lbdb/
COMMENT=		The little brother's database

DEPENDS+=		p5-perl-ldap>=0.20:../../databases/p5-perl-ldap

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--libdir=${PREFIX}/libexec/lbdb/
CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=  --enable-lbdb_dotlock
CONFIGURE_ARGS+=  --without-getent
CONFIGURE_ARGS+=  --without-evolution-addressbook-export
CONFIGURE_ARGS+=  --without-pgp
CONFIGURE_ARGS+=  --without-pgpk

.include "options.mk"

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

EGDIR=			${PREFIX}/share/examples/lbdb
CONF_FILES+=		${EGDIR}/lbdb.rc ${PKG_SYSCONFDIR}/lbdb.rc
CONF_FILES+=		${EGDIR}/lbdb_ldap.rc ${PKG_SYSCONFDIR}/lbdb_ldap.rc

.include "../../mk/bsd.pkg.mk"
