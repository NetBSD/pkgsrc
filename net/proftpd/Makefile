# $NetBSD: Makefile,v 1.35.4.3 2006/12/18 14:28:32 ghen Exp $

DISTNAME=	proftpd-1.3.1rc1
#PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.proftpd.org/distrib/source/ \
		ftp://ftp.servus.at/ProFTPD/distrib/source/ \
		ftp://ftp.fsn.hu/pub/proftpd/distrib/source/ \
		ftp://ftp.middle-earth.it/proftpd/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.proftpd.org/
COMMENT=	FTP server with Apache like configuration

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--disable-sendfile
CONFIGURE_ARGS+=	--enable-ctrls
CONFIGURE_ARGS+=	--enable-nls

CONFIGURE_ENV+=	install_user=${ROOT_USER} install_group=${ROOT_GROUP}

BUILD_DEFS+=	VARBASE

RCD_SCRIPTS=	proftpd

CONF_FILES=	${PREFIX:Q}/share/examples/proftpd/basic.conf \
		${PKG_SYSCONFDIR:Q}/proftpd.conf

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Fixing paths in manual pages.
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	utils/ftpcount.1.in utils/ftptop.1.in utils/ftpwho.1.in
SUBST_SED.man=		-e s,@LOCALSTATEDIR@/run/proftpd,${VARBASE:Q}/run,

INSTALLATION_DIRS+=	share/doc/proftpd
INSTALLATION_DIRS+=	share/examples/proftpd

.include "options.mk"

post-install:
.for i in NEWS README README.IPv6 README.LDAP README.PAM README.capabilities \
          README.classes README.controls README.facl README.modules
	${INSTALL_DATA} ${WRKSRC:Q}/${i:Q} ${PREFIX:Q}/share/doc/proftpd
.endfor
.for i in Configuration.html faq.html license.txt
	${INSTALL_DATA} ${WRKSRC:Q}/doc/${i:Q} ${PREFIX:Q}/share/doc/proftpd
.endfor
	${INSTALL_DATA} ${WRKSRC:Q}/sample-configurations/*.conf \
		${PREFIX:Q}/share/examples/proftpd

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
