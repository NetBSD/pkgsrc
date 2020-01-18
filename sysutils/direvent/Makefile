# $NetBSD: Makefile,v 1.4 2020/01/18 23:35:15 rillig Exp $

DISTNAME=	direvent-5.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=direvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ftp.gnu.org/gnu/direvent/
COMMENT=	Daemon that monitors file system directories for events
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
TEST_TARGET=		check
INFO_FILES=		yes

CONFIGURE_ARGS+=	--disable-nls
LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
