# $NetBSD: Makefile,v 1.58 2010/03/21 21:24:25 kim Exp $

DISTNAME=		proftpd-1.3.3
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.proftpd.org/distrib/source/ \
			ftp://ftp.servus.at/ProFTPD/distrib/source/ \
			ftp://ftp.fsn.hu/pub/proftpd/distrib/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.proftpd.org/
COMMENT=		FTP server with Apache like configuration
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--disable-sendfile
CONFIGURE_ARGS+=	--enable-ctrls
CONFIGURE_ARGS+=	--enable-nls

CONFIGURE_ENV+=		install_user=${ROOT_USER} install_group=${ROOT_GROUP}

BUILD_DEFS+=		VARBASE

RCD_SCRIPTS=		proftpd
REPLACE_PERL+=		contrib/ftpasswd

CONF_FILES=		${PREFIX}/share/examples/proftpd/basic.conf \
			${PKG_SYSCONFDIR}/proftpd.conf

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Fixing paths in manual pages.
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	utils/ftpcount.1.in utils/ftptop.1.in utils/ftpwho.1.in
SUBST_SED.man=		-e s,@LOCALSTATEDIR@/run/proftpd,${VARBASE}/run,

INSTALLATION_DIRS+=	lib/proftpd
INSTALLATION_DIRS+=	share/doc/proftpd
INSTALLATION_DIRS+=	share/examples/proftpd

PLIST_SRC+=		${PKGDIR}/PLIST

.include "options.mk"

post-patch:
	cd ${WRKSRC}/contrib \
	&& ${CP} -p mod_wrap.c mod_wrap.c.orig \
	&& ${SED} -e '/^...\$$Libraries: /s/ -lnsl\$$$$/$$/' \
	    mod_wrap.c.orig > mod_wrap.c

post-install:
.for i in NEWS README README.IPv6 README.LDAP README.PAM README.capabilities \
          README.classes README.controls README.facl README.modules
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/doc/proftpd
.endfor
.for i in Configuration.html faq.html license.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DESTDIR}${PREFIX}/share/doc/proftpd
.endfor
	${INSTALL_DATA} ${WRKSRC}/sample-configurations/*.conf \
		${DESTDIR}${PREFIX}/share/examples/proftpd
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/ftpasswd \
		${DESTDIR}${PREFIX}/share/examples/proftpd

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
