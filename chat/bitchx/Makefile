# $NetBSD: Makefile,v 1.34 2005/03/24 23:43:44 wiz Exp $

DISTNAME=	ircii-pana-1.1-final
PKGNAME=	bitchx-1.1
CATEGORIES=	chat
MASTER_SITES=	http://www.bitchx.org/files/source/ \
		ftp://ftp.bitchx.org/pub/BitchX/source/ \
		ftp://ftp.bitchx.org/pub/BitchX/source/old/

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://www.bitchx.org/
COMMENT=	IRC client based on ircII

# This package is not even remotely 64-bit clean
NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64 *-*-x86_64

WRKSRC=			${WRKDIR}/BitchX
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--with-ssl

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
CFLAGS+=	-DBIND_8_COMPAT
.endif

.if defined(BITCHX_WITH_GTK) && !empty(BITCHX_WITH_GTK:M[Yy][Ee][Ss])
.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
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

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
