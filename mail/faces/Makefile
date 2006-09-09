# $NetBSD: Makefile,v 1.53 2006/09/09 02:43:10 obache Exp $

DISTNAME=	faces-1.6.1
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/faces/faces-1.6.1/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Visual mail, user and print face server

DEPENDS+=	netpbm>=9.2:../../graphics/netpbm

CONFLICTS=	compface-[0-9]*

LICENSE=	faces-license
RESTRICTED=	Distribution not allowed if money exchanged
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}/faces
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		perl:run yacc

MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	CCOMP=${CFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	SVR4LIBS="-lnsl -lsocket -lgen"
MAKE_ENV+=	SYSV=-DSYSV32
MAKE_ENV+=	CC=gcc
MAKE_ENV+=	CPPFLAGS=
.endif

.if ${OPSYS} != "Interix"
MAKE_ENV+=	NISLOOKUP=-DNISLOOKUP
.endif

REPLACE_PERL=	scripts/addxface scripts/deepen scripts/facesaddr \
		scripts/facesall scripts/from.faces scripts/lpqall.faces \
		scripts/mailq.faces scripts/mailqto scripts/mailqto.faces \
		scripts/mkfacesindex scripts/newscheck.faces \
		scripts/newsfrom.faces scripts/rotary.faces

do-configure:
	${LN} -sf Makefile.dist ${WRKSRC}/${MAKE_FILE}
	cd ${WRKSRC};							\
	files="								\
		x11.c							\
		scripts/addxface					\
		scripts/facesall					\
		scripts/mkfacesindex					\
	";								\
	for FILE in $${files}; do					\
		${SED}	-e "s|@PREFIX@|${PREFIX}|g"			\
			$${FILE} > $${FILE}.fixed;			\
		if [ -x $${FILE} ]; then				\
			${CHMOD} +x $${FILE}.fixed;			\
		fi;							\
		${MV} -f $${FILE}.fixed $${FILE};			\
	done

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
