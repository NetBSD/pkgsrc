# $NetBSD: Makefile,v 1.30.2.1 2004/11/02 10:53:15 agc Exp $

DISTNAME=	m4-1.4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=m4/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/directory/gnum4.html
COMMENT=	GNU version of UNIX m4 macro language processor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_HAS_INFODIR=	no
MAKE_ENV+=		INFO_DIR=${INFO_DIR}
INFO_FILES=		m4.info
USE_MAKEINFO=		yes

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS=		--program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.if !defined(GNU_PROGRAM_PREFIX) || ${GNU_PROGRAM_PREFIX} != "g"
PLIST_SUBST+=		GM4_LINK=""
.else
PLIST_SUBST+=		GM4_LINK="@comment "
.endif

pre-build:
	${CHMOD} u+w ${WRKSRC}/checks/stamp-checks

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/m4
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${PREFIX}/share/examples/m4
.if !defined(GNU_PROGRAM_PREFIX) || ${GNU_PROGRAM_PREFIX} != "g"
	${LN} -sf ${GNU_PROGRAM_PREFIX}m4 ${PREFIX}/bin/gm4
.endif

.include "../../mk/bsd.pkg.mk"
