# $NetBSD: Makefile,v 1.22 2003/07/17 21:31:48 grant Exp $
#

DISTNAME=	m4-1.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=m4/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	GNU version of Unix m4 macro-processor

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_NEW_TEXINFO=	yes
INFO_FILES=		m4.info
USE_MAKEINFO=		yes

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
