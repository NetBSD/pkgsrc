# $NetBSD: Makefile,v 1.14 1999/08/31 19:26:40 jlam Exp $
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

.if ${OPSYS} == "NetBSD"
SKEY_OPTION=	--with-skey
.elif ${OPSYS} == "SunOS"
SKEY_OPTION=	--without-skey
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-C2 ${SKEY_OPTION} --with-nbsdops --disable-path-info

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sudo
	${INSTALL_DATA} ${WRKSRC}/sudoers ${PREFIX}/share/examples/sudo/sudoers
	${INSTALL_DATA} ${WRKSRC}/sample.sudoers \
		${PREFIX}/share/examples/sudo/sudoers.sample

.include "../../mk/bsd.pkg.mk"
