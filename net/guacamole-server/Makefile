# $NetBSD: Makefile,v 1.40 2022/06/28 11:35:00 wiz Exp $

DISTNAME=	guacamole-server-1.0.0
PKGREVISION=	18
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_APACHE:=guacamole/${PKGVERSION_NOREV}/source/}

MAINTAINER=	jperkin@joyent.com
HOMEPAGE=	https://guacamole.incubator.apache.org/
COMMENT=	Clientless remote desktop gateway
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS=	perl pkg-config

EGDIR=			${PREFIX}/share/examples/guacamole
PKG_SYSCONFSUBDIR=	guacamole
SMF_NAME=		guacamole

CONFIGURE_ARGS+=	--with-guacd-conf=${PKG_SYSCONFDIR}/guacd.conf
CONFIGURE_ARGS+=	--with-pango
CONFIGURE_ARGS+=	--with-pulse
CONFIGURE_ARGS+=	--with-rdp
CONFIGURE_ARGS+=	--with-ssh
CONFIGURE_ARGS+=	--with-ssl
CONFIGURE_ARGS+=	--with-telnet
CONFIGURE_ARGS+=	--with-terminal
CONFIGURE_ARGS+=	--with-vnc
CONFIGURE_ARGS+=	--with-vorbis
CONFIGURE_ARGS+=	--with-webp

CFLAGS.SunOS+=	-D__EXTENSIONS__	# getopt()

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	src/guacd/man/guacd.conf.5
SUBST_SED.manpath=	-e 's,/etc/guacamole,${PKG_SYSCONFDIR},g'
SUBST_NOOP_OK.manpath=	yes # PKG_SYSCONFBASE=/etc

REPLACE_PERL+=		src/protocols/rdp/keymaps/generate.pl

INSTALLATION_DIRS=	share/examples/guacamole

CONF_FILES=	${EGDIR}/guacd.conf ${PKG_SYSCONFDIR}/guacd.conf

post-install:
	${INSTALL_DATA} ${FILESDIR}/guacd.conf \
	    ${DESTDIR}${PREFIX}/share/examples/guacamole/guacd.conf

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/ossp-uuid/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../net/freerdp2/buildlink3.mk"
.include "../../net/libtelnet/buildlink3.mk"
.include "../../net/libvncserver/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
