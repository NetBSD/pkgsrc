# $NetBSD: Makefile,v 1.2 2005/05/22 20:07:45 jlam Exp $

DISTNAME=		${PKGNAME:S/-/_/}
PKGNAME=		lbdb-0.29
CATEGORIES=		databases
MASTER_SITES=		http://www.spinnaker.de/debian/

MAINTAINER=		reilles@loria.fr
HOMEPAGE=		http://www.spinnaker.de/lbdb/
COMMENT=		The little brother's database

DEPENDS+=		p5-perl-ldap>=0.20:../../databases/p5-perl-ldap

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_PERL5=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--libdir=${PREFIX}/libexec/lbdb/
CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFDIR}

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

EGDIR=			${PREFIX}/share/examples/lbdb
CONF_FILES+=		${EGDIR}/lbdb.rc ${PKG_SYSCONFDIR}/lbdb.rc
CONF_FILES+=		${EGDIR}/lbdb_ldap.rc ${PKG_SYSCONFDIR}/lbdb_ldap.rc

.include "../../mk/bsd.pkg.mk"
