# $NetBSD: Makefile,v 1.14 2015/03/15 15:10:01 tnn Exp $

DISTNAME=	xfsprogs-2.7.3.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://oss.sgi.com/projects/xfs/cmd_tars/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oss.sgi.com/projects/xfs/
COMMENT=	XFS filesystem manipulation utilities

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake autoconf msgmerge
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-readline
CONFIGURE_ENV+=		INSTALL_USER=${ROOT_USER} INSTALL_GROUP=${ROOT_GROUP}
CONFIGURE_ENV+=		MSGFMT=${TOOLS_PATH.msgfmt:Q}
CONFIGURE_ENV+=		MSGMERGE=${TOOLS_PATH.msgmerge:Q}

INSTALL_SH_OVERRIDE=	no

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			PKG_MAN_DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_TARGET=

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
