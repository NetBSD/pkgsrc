# $NetBSD: Makefile,v 1.48 2012/09/11 19:46:55 asau Exp $

DISTNAME=	sharutils-4.11.1
PKGREVISION=	2
PKGNAME=	g${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=sharutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sharutils/sharutils.html
COMMENT=	Allow packing and unpacking of shell archives
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

AUTO_MKDIRS=		yes

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALL_TARGET=		install install-man
INFO_FILES=		yes
USE_TOOLS+=		makeinfo msgfmt sh:run

CONFIGURE_ARGS+=	--disable-uucode
CONFIGURE_ENV+=		SH=${TOOLS_SH}

CONFIGURE_ARGS+=	--program-prefix=g

post-install:
.for f in shar unshar
	${LN} -sf ${PREFIX}/bin/g${f} ${DESTDIR}${PREFIX}/gnu/bin/${f}
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f}.1 ${DESTDIR}${PREFIX}/gnu/man/man1/${f}.1
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
