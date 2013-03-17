# $NetBSD: Makefile,v 1.69.2.1 2013/03/17 11:45:23 tron Exp $

DISTNAME=	proftpd-1.3.4c
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.proftpd.org/distrib/source/ \
		ftp://ftp.servus.at/ProFTPD/distrib/source/ \
		ftp://ftp.fsn.hu/pub/proftpd/distrib/source/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.proftpd.org/
COMMENT=	FTP server with Apache like configuration
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=		gmake intltool msgfmt perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/run
CONFIGURE_ARGS+=	--disable-sendfile
CONFIGURE_ARGS+=	--enable-ctrls
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ENV+=		install_group=${ROOT_GROUP}
CONFIGURE_ENV+=		install_user=${ROOT_USER}

BUILD_DEFS+=		VARBASE

RCD_SCRIPTS=		proftpd
REPLACE_PERL+=		contrib/ftpasswd
REPLACE_PERL+=		contrib/ftpmail
REPLACE_PERL+=		contrib/ftpquota
REPLACE_PERL+=		src/prxs.in

CONF_FILES=		${PREFIX}/share/examples/proftpd/basic.conf \
			${PKG_SYSCONFDIR}/proftpd.conf

INSTALLATION_DIRS+=	lib/proftpd
INSTALLATION_DIRS+=	share/doc/proftpd
INSTALLATION_DIRS+=	share/examples/proftpd

PLIST_SRC+=		${PKGDIR}/PLIST

.include "options.mk"

SUBST_CLASSES+=		libwrap
SUBST_STAGE.libwrap=	post-patch
SUBST_FILES.libwrap=	contrib/mod_wrap.c
SUBST_SED.libwrap=	-e '/^...\$$Libraries: /s/ -lnsl\$$$$/$$/'

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
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
