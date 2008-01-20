# $NetBSD: Makefile,v 1.7 2008/01/20 07:25:13 obache Exp $

DISTNAME=	xfsprogs-2.7.3.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://oss.sgi.com/projects/xfs/cmd_tars/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oss.sgi.com/projects/xfs/
COMMENT=	XFS filesystem manipulation utilities

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake autoconf msgfmt
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=--enable-readline
CONFIGURE_ENV+=	INSTALL_USER=${ROOT_USER} INSTALL_GROUP=${ROOT_GROUP}
INSTALL_SH_OVERRIDE=	no

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_TARGET=

.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
