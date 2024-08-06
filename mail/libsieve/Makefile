# $NetBSD: Makefile,v 1.16 2024/08/06 13:04:56 tnn Exp $
#

DISTNAME=		libsieve-2.3.1
CATEGORIES=		mail
# https://github.com/sodabrew/libsieve/issues/5
#MASTER_SITES=		https://github.com/downloads/sodabrew/libsieve/
MASTER_SITES=		https://src.fedoraproject.org/repo/extras/libsieve/libsieve-2.3.1.tar.gz/bb48eecf877cc7fdb2b0dfe757b48d7a/
MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/sodabrew/libsieve
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
