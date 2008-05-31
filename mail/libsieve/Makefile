# $NetBSD: Makefile,v 1.10 2008/05/31 15:05:40 obache Exp $
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

SUBST_CLASSES+=			stripcr
SUBST_STAGE.stripcr=		post-extract
SUBST_FILES.stripcr=		src/sv_util/exception.*
SUBST_FILTER_CMD.stripcr=	${TR} -d '\r'

.include "../../mk/bsd.pkg.mk"
