# $NetBSD: Makefile,v 1.22 2000/02/28 01:55:26 thorpej Exp $
# FreeBSD Id: Makefile,v 1.9 1997/11/12 03:24:41 obrien Exp
#

DISTNAME=	sudo-1.6.2p1
CATEGORIES=	security
MASTER_SITES=	http://www.courtesan.com/sudo/dist/ \
		ftp://ftp.courtesan.com/pub/sudo/ \
		ftp://ftp.cs.colorado.edu/pub/sudo/ \
		ftp://ftp.uu.net/pub/security/sudo/ \
		ftp://ftp.tux.org/pub/security/sudo/

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

# XXX Currently uses API features present only in Heimdal.
.if defined(USE_HEIMDAL)
.if defined(KERBEROS) && ${KERBEROS} == 5
USE_KERBEROS=	yes
CONFIGURE_ARGS+=--with-kerb5
.else
CONFIGURE_ARGS+=--without-kerb5
.endif
.endif

CONFIGURE_ARGS+=--with-nbsdops --disable-path-info

# The UPGRADE file has important information on upgrading from a previous
# version of sudo.
#
MESSAGE_FILE=	${WRKSRC}/UPGRADE

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sudo
	${INSTALL_DATA} ${WRKSRC}/sudoers ${PREFIX}/share/examples/sudo/sudoers
	${INSTALL_DATA} ${WRKSRC}/sample.sudoers \
		${PREFIX}/share/examples/sudo/sudoers.sample

.include "../../mk/bsd.pkg.mk"
