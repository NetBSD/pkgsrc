# $NetBSD: Makefile,v 1.24 2001/11/30 16:29:28 jlam Exp $

DISTNAME=	faces-1.6.1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/faces
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/faces/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	visual mail, user and print face server

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
	for file in $${files}; do					\
		${SED}	-e "s|@PREFIX@|${PREFIX}|g"			\
			$${file} > $${file}.fixed;			\
		if [ -x $${file} ]; then				\
			${CHMOD} +x $${file}.fixed;			\
		fi;							\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
