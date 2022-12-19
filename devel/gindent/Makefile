# $NetBSD: Makefile,v 1.57 2022/12/19 10:21:27 wiz Exp $

DISTNAME=	indent-2.2.12
PKGNAME=	g${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=indent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/indent/indent.html
COMMENT=	GNU version of pretty-printer for C source code
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes
USE_TOOLS+=		makeinfo

INSTALLATION_DIRS+=	${PKGGNUDIR}bin ${PKGGNUDIR}${PKGMANDIR}/man1

# code not clean enough
BUILDLINK_TRANSFORM+=	rm:-Werror

post-install:
	${LN} -sf ${PREFIX}/bin/gindent ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/indent
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/gindent.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/indent.1
	${LN} -sf ${PREFIX}/bin/gtexinfo2man ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/texinfo2man

CONFIGURE_ARGS+=	--program-prefix=g

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
