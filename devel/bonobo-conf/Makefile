# $NetBSD: Makefile,v 1.1.1.1 2001/08/11 13:45:43 rh Exp $
#

DISTNAME=		bonobo-conf-0.10
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/bonobo-conf/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Bonobo configuration system

DEPENDS+=		oaf>=0.6.2:../../devel/oaf
DEPENDS+=		GConf>=0.11:../../devel/GConf
DEPENDS+=		bonobo>=0.37:../../devel/bonobo
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_LIBINTL=		YES
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

.include "../../mk/bsd.pkg.mk"
