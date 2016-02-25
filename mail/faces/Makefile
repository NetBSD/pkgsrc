# $NetBSD: Makefile,v 1.64 2016/02/25 15:00:50 jperkin Exp $

DISTNAME=	faces-1.6.1
PKGREVISION=	9
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/faces/faces-1.6.1/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Visual mail, user and print face server
LICENSE=	faces-license

RESTRICTED=	Distribution not allowed if money exchanged
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DEPENDS+=	netpbm>=9.2:../../graphics/netpbm

CONFLICTS=	compface-[0-9]*

WRKSRC=			${WRKDIR}/faces
USE_LIBTOOL=		YES
USE_TOOLS+=		perl:run yacc

MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	CCOMP=${CFLAGS:M*:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}

.include "../../mk/bsd.prefs.mk"

MAKE_ENV.SunOS+=	SVR4LIBS="-lnsl -lsocket -lgen"
MAKE_ENV.SunOS+=	SYSV=-DSYSV32
MAKE_ENV.SunOS+=	CC=gcc
MAKE_ENV.SunOS+=	CPPFLAGS=

.if ${OPSYS} != "Interix"
MAKE_ENV+=	NISLOOKUP=-DNISLOOKUP
.endif

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR:Q}${PREFIX:Q}	\
			MANDIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}

INSTALLATION_DIRS+=	bin lib include ${PKGMANDIR}/man1 ${PKGMANDIR}/man3

REPLACE_PERL=	scripts/addxface scripts/deepen scripts/facesaddr \
		scripts/facesall scripts/from.faces scripts/lpqall.faces \
		scripts/mailq.faces scripts/mailqto scripts/mailqto.faces \
		scripts/mkfacesindex scripts/newscheck.faces \
		scripts/newsfrom.faces scripts/rotary.faces

post-extract:
	${LN} -sf Makefile.dist ${WRKSRC}/${MAKE_FILE}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=							\
		x11.c							\
		scripts/addxface					\
		scripts/facesall					\
		scripts/mkfacesindex
SUBST_VARS.prefix=	PREFIX

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
