# $NetBSD: Makefile,v 1.26 2002/07/07 14:25:52 tron Exp $

DISTNAME=	faces-1.6.1
PKGREVISION=	2
WRKSRC=		${WRKDIR}/faces
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/faces/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	visual mail, user and print face server

DEPENDS+=	netpbm>=9.2:../../graphics/netpbm

LICENSE=	limited-redistribution
RESTRICTED=	"Distribution not allowed if money exchanged"

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES

MAKE_FLAGS+=	PREFIX="${PREFIX}"
MAKE_FLAGS+=	CCOMP="${CFLAGS}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	SVR4LIBS="-lnsl -lsocket -lgen"
MAKE_ENV+=	SYSV=-DSYSV32
MAKE_ENV+=	CC=gcc
MAKE_ENV+=	CPPFLAGS=
.endif

do-configure:
	${LN} -sf Makefile.dist ${WRKSRC}/${MAKEFILE}
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

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
