# $NetBSD: Makefile,v 1.9.2.1 2002/05/11 02:08:48 jlam Exp $

DISTNAME=	sharutils-4.2.1
PKGNAME=	g${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=sharutils/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/sharutils/sharutils.html
COMMENT=	Allow packing and unpacking of shell archives

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK2_ONLY=	yes

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --program-prefix=g --disable-uucode
CONFIGURE_ENV+=	PKGLOCALEDIR=${PKGLOCALEDIR}
INSTALL_TARGET= install install-man
INFO_FILES=	remsync.info sharutils.info
TEXINFO_OVERRIDE=	YES

post-patch:
	@${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/po/sharutils.pot

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
