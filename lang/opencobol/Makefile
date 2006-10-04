# $NetBSD: Makefile,v 1.12 2006/10/04 21:46:13 wiz Exp $
#

DISTNAME=		open-cobol-0.23
PKGNAME=		${DISTNAME:S/-//}
PKGREVISION=		4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=open-cobol/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.opencobol.org/
COMMENT=		Open-source COBOL compiler

GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
INFO_FILES=		# PLIST
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

CONFIGURE_ARGS+=	--without-readline
CONFIGURE_ARGS+=	--with-lfs
CONFIGURE_ENV+=		NCURSES_LIB=${BUILDLINK_LDADD.ncurses:Q}

EGDIR=			${PREFIX}/share/examples/open-cobol
CONF_FILES=		${EGDIR}/libconf.conf ${PKG_SYSCONFDIR}/libconf.conf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
