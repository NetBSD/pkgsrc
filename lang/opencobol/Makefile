# $NetBSD: Makefile,v 1.10 2006/04/04 19:21:39 jlam Exp $
#

DISTNAME=		open-cobol-0.23
PKGNAME=		${DISTNAME:S/-//}
PKGREVISION=		4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=open-cobol/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://open-cobol.sourceforge.net/
COMMENT=		Open-source COBOL compiler

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
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
