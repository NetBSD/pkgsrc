# $NetBSD: Makefile,v 1.51 2012/10/31 11:17:00 asau Exp $
#

DISTNAME=	indent-2.2.9
PKGNAME=	g${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=indent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/indent/indent.html
COMMENT=	GNU version of pretty-printer for C source code

LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes
MAKE_JOBS_SAFE=		no

AUTO_MKDIRS=		yes

post-install:
	${LN} -sf ${PREFIX}/bin/gindent ${DESTDIR}${PREFIX}/gnu/bin/indent
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/gindent.1 ${DESTDIR}${PREFIX}/gnu/man/man1/indent.1
	${LN} -sf ${PREFIX}/bin/gtexinfo2man ${DESTDIR}${PREFIX}/gnu/bin/texinfo2man

CONFIGURE_ARGS+=	--program-prefix=g

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
