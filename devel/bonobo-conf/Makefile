# $NetBSD: Makefile,v 1.3 2002/01/16 01:37:48 rh Exp $

DISTNAME=		bonobo-conf-0.14
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/bonobo-conf/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Bonobo configuration system

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES

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
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
