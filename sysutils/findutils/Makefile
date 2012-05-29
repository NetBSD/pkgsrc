# $NetBSD: Makefile,v 1.29 2012/05/29 22:02:31 cheusov Exp $

DISTNAME=	findutils-4.2.33
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=findutils/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/findutils/findutils.html
COMMENT=	The GNU find, xargs and locate utilities
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		YES
INFO_FILES=		YES
PKG_DESTDIR_SUPPORT=	user-destdir
USE_PKGLOCALEDIR=	YES

LDFLAGS.IRIX+=		-lgen

CONFIGURE_ARGS+=	--program-prefix=g

INSTALLATION_DIRS=	gnu/bin

post-install:
	ln -s ../../bin/gfind     ${DESTDIR}${PREFIX}/gnu/bin/find
	ln -s ../../bin/glocate   ${DESTDIR}${PREFIX}/gnu/bin/locate
	ln -s ../../bin/gupdatedb ${DESTDIR}${PREFIX}/gnu/bin/updatedb
	ln -s ../../bin/gxargs    ${DESTDIR}${PREFIX}/gnu/bin/xargs

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
