# $NetBSD: Makefile,v 1.14 2014/12/05 08:48:49 obache Exp $
#

DISTNAME=		libsieve-2.3.1
CATEGORIES=		mail
MASTER_SITES=		https://github.com/downloads/sodabrew/libsieve/

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://sodabrew.com/libsieve/
COMMENT=		Library for parsing, sorting and filtering mail
LICENSE=		gnu-lgpl-v2.1

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libsieve.pc.in

SUBST_CLASSES+=			stripcr
SUBST_STAGE.stripcr=		post-extract
SUBST_FILES.stripcr=		src/sv_util/exception.*
SUBST_FILTER_CMD.stripcr=	${TR} -d '\r'

.include "../../mk/bsd.pkg.mk"
