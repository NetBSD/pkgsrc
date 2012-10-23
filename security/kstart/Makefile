# $NetBSD: Makefile,v 1.3 2012/10/23 18:16:31 asau Exp $

DISTNAME=	kstart-4.1
CATEGORIES=	sysutils
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://www.eyrie.org/~eagle/software/kstart/
COMMENT=	Kerberos v5 kinit daemon that uses keytabs
LICENSE=	mit

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-k4start
CONFIGURE_ARGS+=	--enable-setpag

# As the NetBSD base system doesn't ship with afslog
# and pkgsrc heimdal and pkgsrc openafs conflict;
# the path to (ak|afs)log is configurable.

BUILD_DEFS+= KSTART_PATH_AKLOG
KSTART_PATH_AKLOG?= ${PREFIX}/bin/afslog
.include "../../mk/bsd.prefs.mk"
CONFIGURE_ARGS+=	--with-aklog=${KSTART_PATH_AKLOG:Q}

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
