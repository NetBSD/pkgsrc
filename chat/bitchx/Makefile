# $NetBSD: Makefile,v 1.22 2003/09/27 17:07:35 grant Exp $
#

DISTNAME=	ircii-pana-1.0c19
PKGNAME=	bitchx-1.0.3.19
PKGREVISION=	3
WRKSRC=		${WRKDIR}/BitchX
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.bitchx.org/pub/BitchX/source/ \
		ftp://ftp.bitchx.org/pub/BitchX/source/old/

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://www.bitchx.org/
COMMENT=	IRC client based on ircII

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--with-ssl

.if defined(BITCHX_WITH_GTK) && !empty(BITCHX_WITH_GTK:M[Yy][Ee][Ss])
.include "../../graphics/imlib/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
CONFIGURE_ARGS+=	--with-gtk
CFLAGS+=		-I${PREFIX}/include/gnome-1.0
PLIST_SUBST+=		GTK="gtk"
PLIST_SUBST+=		NOT_GTK="@comment "
.else
PLIST_SUBST+=		GTK=
PLIST_SUBST+=		NOT_GTK=
.endif

post-patch:
	@${MV} ${WRKSRC}/doc/BitchX.1 ${WRKSRC}/doc/BitchX.1.orig
	@${SED} ${FILES_SUBST_SED} \
		${WRKSRC}/doc/BitchX.1.orig > ${WRKSRC}/doc/BitchX.1

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../mk/curses.buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
