# $NetBSD: Makefile,v 1.55 2017/04/05 17:23:07 adam Exp $

DISTNAME=	sharutils-4.15.2
PKGNAME=	g${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=sharutils/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sharutils/sharutils.html
COMMENT=	Allow packing and unpacking of shell archives
LICENSE=	gnu-gpl-v3

AUTO_MKDIRS=		yes

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-prefix=g
CONFIGURE_ENV+=		SH=${TOOLS_SH}

INSTALL_TARGET=		install install-man
INFO_FILES=		yes
USE_TOOLS+=		makeinfo msgfmt sh:run

.include "../../mk/bsd.prefs.mk"

pre-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/charset.alias

post-install:
.for f in shar unshar
	${LN} -sf ${PREFIX}/bin/g${f} ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/${f}
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f}.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/${f}.1
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
