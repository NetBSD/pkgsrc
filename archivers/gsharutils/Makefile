# $NetBSD: Makefile,v 1.46 2012/05/29 20:52:55 cheusov Exp $

DISTNAME=	sharutils-4.11.1
PKGREVISION=	1
PKGNAME=	g${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=sharutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sharutils/sharutils.html
COMMENT=	Allow packing and unpacking of shell archives
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	gnu/bin

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALL_TARGET=		install install-man
INFO_FILES=		yes
USE_TOOLS+=		makeinfo msgfmt sh:run

CONFIGURE_ARGS+=	--disable-uucode
CONFIGURE_ENV+=		SH=${TOOLS_SH}

CONFIGURE_ARGS+=	--program-prefix=g

post-install:
	set -e; cd ${DESTDIR}${PREFIX}/gnu/bin; \
	ln -s ../../bin/gshar shar; \
	ln -s ../../bin/gunshar unshar

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
