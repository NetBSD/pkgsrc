# $NetBSD: Makefile,v 1.9 2007/12/17 11:32:57 obache Exp $
#

DISTNAME=		libsieve-2.2.6
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libsieve/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://libsieve.sourceforge.net/
COMMENT=		Library for parsing, sorting and filtering mail

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		flex bison
GNU_CONFIGURE=		yes

CONFIGURE_DIRS=		src

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
