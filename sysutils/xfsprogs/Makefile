# $NetBSD: Makefile,v 1.2 2006/02/05 23:10:58 joerg Exp $

DISTNAME=	xfsprogs-2.7.3.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://oss.sgi.com/projects/xfs/cmd_tars/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://oss.sgi.com/projects/xfs
COMMENT=	XFS filesystem manipulation utilities

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake autoconf
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=--enable-readline
CONFIGURE_ENV+=	INSTALL_USER=${ROOT_USER} INSTALL_GROUP=${ROOT_GROUP}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_TARGET=	

.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
