# $NetBSD: Makefile,v 1.6 2002/08/25 19:22:23 jlam Exp $

DISTNAME=		bonobo-conf-0.14
PKGREVISION=		2
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/bonobo-conf/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Bonobo configuration system

BUILD_DEPENDS+=		autoconf-[0-9]*:../../devel/autoconf
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES

pre-configure:
	cd ${WRKSRC} && autoconf

post-configure:
	${RM} -f ${WRKSRC}/libtool
	${LN} -s ${LOCALBASE}/bin/libtool ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bonobo-conf
.for doc in bonobo-conf.pdf bonobo-conf.sgml
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${PREFIX}/share/doc/bonobo-conf
.endfor

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/GConf/buildlink.mk"
.include "../../devel/popt/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
