# $NetBSD: Makefile,v 1.22 2000/11/30 00:15:51 wiz Exp $
# FreeBSD Id: Makefile,v 1.6 1998/12/28 01:02:05 vanilla Exp
#

DISTNAME=		gqmpeg-0.7.3
CATEGORIES=		audio
MASTER_SITES=		http://www.netpedia.net/hosting/gqview/packages/

MAINTAINER=		rxg@ms25.url.com.tw
HOMEPAGE=		http://www.netpedia.net/hosting/gqview/mpeg-index.html

DEPENDS+=		gdk-pixbuf>=0.8.0nb1:../../graphics/gdk-pixbuf
BUILD_DEPENDS+=		msgfmt:../../devel/gettext
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		mpg123-0.59r:../../audio/mpg123

USE_LIBINTL=		# defined
USE_X11BASE=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-I${LOCALBASE}/include		# libintl.h
DEINSTALL_FILE=		${WRKDIR}/DEINSTALL

post-build:
	${SED} -e 's#@PREFIX@#${PREFIX}#g' < ${PKGDIR}/DEINSTALL	\
		> ${WRKDIR}/DEINSTALL

.include "../../mk/bsd.pkg.mk"
