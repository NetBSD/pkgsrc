# $NetBSD: Makefile,v 1.33 2016/03/05 11:28:20 jperkin Exp $
#

DISTNAME=	aegis-4.24.2
PKGREVISION=	10
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aegis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aegis.sourceforge.net/
COMMENT=	Aegis is a transaction base software configuration management system
LICENSE=	gnu-gpl-v3

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		groff gsoelim msgfmt perl:run yacc patch:run

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Mgcc)
CXXFLAGS+=	-std=gnu++0x
.endif

AEGIS_USER_UID?=	3
AEGIS_USER_GID?=	3

CONFIGURE_ARGS+=	--with-nlsdir=${_PKGLOCALEDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-no-aegis-configured
CONFIGURE_ARGS+=	--sharedstatedir=${PREFIX}/com/aegis
CONFIGURE_ENV+=		PATCH=${PATCH:Q}
CONFIGURE_ENV+=		AEGIS_UID=${AEGIS_USER_UID:Q}
CONFIGURE_ENV+=		AEGIS_GID=${AEGIS_USER_GID:Q}

EGDIR=			${PREFIX}/share/examples/aegis
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

CONF_FILES+=		${EGDIR}/profile.d/aegis.csh ${PKG_SYSCONFDIR}/profile.d/aegis.csh
CONF_FILES+=		${EGDIR}/profile.d/aegis.sh ${PKG_SYSCONFDIR}/profile.d/aegis.sh

SPECIAL_PERMS+=		bin/aegis ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=		bin/aeimport ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=		bin/aelock ${SETUID_ROOT_PERMS}

OWN_DIRS_PERMS+=	com/aegis ${AEGIS_USER_UID} ${AEGIS_USER_GID} 2755
MAKE_DIRS+=		${PKG_SYSCONFDIR}/profile.d

BUILD_DEFS+=		AEGIS_USER_UID AEGIS_USER_GID

TEST_TARGET=		sure

AUTO_MKDIRS=		yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
