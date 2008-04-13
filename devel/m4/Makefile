# $NetBSD: Makefile,v 1.52.6.1 2008/04/13 11:45:17 spz Exp $

DISTNAME=	m4-1.4.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=m4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://directory.fsf.org/gnum4.html
COMMENT=	GNU version of UNIX m4 macro language processor

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
INFO_FILES=		yes
#LICENSE=		GPLv3

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.if !defined(GNU_PROGRAM_PREFIX) || ${GNU_PROGRAM_PREFIX} != "g"
PLIST_SUBST+=		GM4_LINK=""
.else
PLIST_SUBST+=		GM4_LINK="@comment "
.endif

.if ${OPSYS} == "DragonFly"
post-patch:
	${CP} ${FILESDIR}/bsd-fflush.c ${WRKSRC}/lib/fflush.c
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/m4
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${DESTDIR}${PREFIX}/share/examples/m4
.if !defined(GNU_PROGRAM_PREFIX) || ${GNU_PROGRAM_PREFIX} != "g"
	${LN} -sf ${GNU_PROGRAM_PREFIX}m4 ${DESTDIR}${PREFIX}/bin/gm4
.endif

.include "../../mk/bsd.pkg.mk"
