# $NetBSD: Makefile,v 1.49 2012/05/29 21:07:33 cheusov Exp $
#

DISTNAME=	indent-2.2.9
PKGNAME=	g${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=indent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/indent/indent.html
COMMENT=	GNU version of pretty-printer for C source code

LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes
MAKE_JOBS_SAFE=		no

INSTALLATION_DIRS+=	gnu/bin

post-install:
	ln -s ${PREFIX}/bin/gindent      ${DESTDIR}${PREFIX}/gnu/bin/indent
	ln -s ${PREFIX}/bin/gtexinfo2man ${DESTDIR}${PREFIX}/gnu/bin/texinfo2man

CONFIGURE_ARGS+=	--program-prefix=g

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
