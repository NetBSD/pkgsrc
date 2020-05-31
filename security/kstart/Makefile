# $NetBSD: Makefile,v 1.6 2020/05/31 09:36:44 rillig Exp $

DISTNAME=	kstart-4.2
CATEGORIES=	sysutils
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	https://www.eyrie.org/~eagle/software/kstart/
COMMENT=	Kerberos v5 kinit daemon that uses keytabs
LICENSE=	mit

GNU_CONFIGURE=	yes

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
