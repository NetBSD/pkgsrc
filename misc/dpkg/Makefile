# $NetBSD: Makefile,v 1.6 2005/12/05 23:55:12 rillig Exp $
#

DISTNAME=	${PKGNAME:S,-,_,}
PKGNAME=	dpkg-1.10.24
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/d/dpkg/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://packages.debian.org/stable/base/dpkg.html
COMMENT=	Package maintenance system for Debian

BUILD_USES_MSGFMT=	yes

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl
USE_NCURSES=		# tigetstr()
USE_PKGINSTALL=		yes

REPLACE_PERL=		${WRKSRC}/scripts/*.pl

ADMIN_DIR=		${PREFIX}/var/db

CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-start-stop-daemon=no
CONFIGURE_ARGS+=	--with-sgml-doc=no
CONFIGURE_ARGS+=	--with-admindir=${ADMIN_DIR:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/dpkg

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
