# $NetBSD: Makefile,v 1.18 1999/09/14 02:32:26 kim Exp $
# FreeBSD Id: Makefile,v 1.9 1997/11/12 03:24:41 obrien Exp
#

DISTNAME=	cu-sudo.v1.5.9p4
PKGNAME=	sudo-1.5.9p4
WRKSRC=		${WRKDIR}/sudo.v1.5.9p4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cs.colorado.edu/pub/sudo/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.courtesan.com/sudo/

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=--with-skey
.elif ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=--without-skey
.endif

.if defined(KERBEROS) && ${KERBEROS} == 4
USE_KERBEROS=	yes
CONFIGURE_ARGS+=--with-kerb4
.else
CONFIGURE_ARGS+=--without-kerb4
.endif

.if defined(KERBEROS) && ${KERBEROS} == 5
USE_KERBEROS=	yes
CONFIGURE_ARGS+=--with-kerb5
.else
CONFIGURE_ARGS+=--without-kerb5
.endif

CONFIGURE_ARGS+=--with-C2 --with-nbsdops --disable-path-info

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sudo
	${INSTALL_DATA} ${WRKSRC}/sudoers ${PREFIX}/share/examples/sudo/sudoers
	${INSTALL_DATA} ${WRKSRC}/sample.sudoers \
		${PREFIX}/share/examples/sudo/sudoers.sample

.include "../../mk/bsd.pkg.mk"
