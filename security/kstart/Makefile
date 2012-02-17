# $NetBSD: Makefile,v 1.2 2012/02/17 18:26:00 jakllsch Exp $

DISTNAME=	kstart-4.1
CATEGORIES=	sysutils
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://www.eyrie.org/~eagle/software/kstart/
COMMENT=	Kerberos v5 kinit daemon that uses keytabs
LICENSE=	mit

PKG_DESTDIR_SUPPORT= user-destdir

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
