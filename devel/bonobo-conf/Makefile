# $NetBSD: Makefile,v 1.20 2004/04/25 04:16:43 xtraeme Exp $

DISTNAME=		bonobo-conf-0.14
PKGREVISION=		8
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/bonobo-conf/0.14/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Bonobo configuration system

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bonobo-conf
.for doc in bonobo-conf.pdf bonobo-conf.sgml
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${PREFIX}/share/doc/bonobo-conf
.endfor

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/GConf/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/oaf/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
