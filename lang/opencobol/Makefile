# $NetBSD: Makefile,v 1.1.1.1 2004/06/29 02:57:36 xtraeme Exp $
#

DISTNAME=		open-cobol-0.23
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=open-cobol/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://open-cobol.sourceforge.net/
COMMENT=		Open-source COBOL compiler

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes

INFO_FILES=		open-cobol.info

CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-lfs

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/libconf.conf ${PKG_SYSCONFDIR}/libconf.conf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libtool/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
