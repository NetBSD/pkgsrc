# $NetBSD: Makefile,v 1.37 2011/01/13 13:39:11 wiz Exp $

DISTNAME=	gimp-print-4.2.7
PKGNAME=	gimp-print-cups-4.2.7
PKGREVISION=	10
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	GIMP print plugin

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake lex
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-escputil=no --enable-libgimpprint=no
CONFIGURE_ARGS+=	--with-cups=${PREFIX:Q}
CONFIGURE_ARGS+=	--without-samples --without-user-guide
CONFIGURE_ARGS+=	--without-gimp --without-translated-ppds
CONFIGURE_ARGS+=	--sysconfdir=${EGDIR:Q}
PKG_SYSCONFSUBDIR=	cups

EGDIR=		${PREFIX}/share/examples/cups
CONF_FILES=	${EGDIR}/command.types ${PKG_SYSCONFDIR}/command.types

.include "../../print/cups/buildlink3.mk"
.include "../../print/gimp-print-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
