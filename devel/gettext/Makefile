# $NetBSD: Makefile,v 1.4 1998/12/28 20:17:39 tron Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/08/09 15:13:33 kuriyama Exp
#

DISTNAME=	gettext-0.10.35
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	tron@netbsd.org

CONFLICTS=	gettext-*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

INFO_FILES=	gettext.info

.include "../../mk/bsd.pkg.mk"
