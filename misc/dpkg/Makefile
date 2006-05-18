# $NetBSD: Makefile,v 1.12 2006/05/18 20:29:59 wiz Exp $
#

DISTNAME=	${PKGNAME_NOREV:S,-,_,}
PKGNAME=	dpkg-1.10.24
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/d/dpkg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.debian.org/stable/base/dpkg.html
COMMENT=	Package maintenance system for Debian

BROKEN_IN=	pkgsrc-2006Q1

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt perl
USE_NCURSES=		# tigetstr()

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
