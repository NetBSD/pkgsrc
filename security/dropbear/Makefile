# $NetBSD: Makefile,v 1.23 2007/09/06 19:15:10 jlam Exp $

DISTNAME=	dropbear-0.50
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://matt.ucc.asn.au/dropbear/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://matt.ucc.asn.au/dropbear/dropbear.html
COMMENT=	SSH2 server, aimed at embedded market

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_OPTIONS_VAR=	PKG_OPTIONS.dropbear
PKG_SUPPORTED_OPTIONS=	pam
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pam
.endif

MAKEFLAGS+=	ROOT_USER=${ROOT_USER:Q} ROOT_GROUP=${ROOT_GROUP:Q}

SUBST_CLASSES+=		config
SUBST_MESSAGE.config=	Fixing path to config directory.
SUBST_STAGE.config=	post-build
SUBST_FILES.config=	dropbear.8 dropbearkey.8
SUBST_SED.config=	-e "s,/etc/dropbear/,"${PKG_SYSCONFDIR:Q}"/dropbear/,g"

INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man8

post-install:
	${INSTALL_MAN} ${WRKSRC}/dbclient.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/dropbear.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/dropbearkey.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dropbear
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dropbear

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
