# $NetBSD: Makefile,v 1.18 2001/02/03 01:52:19 dmcmahill Exp $
# FreeBSD Id: Makefile,v 1.5 1997/11/17 18:47:53 max Exp
#

DISTNAME=	faces-1.6.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/faces/ \
		ftp://odie.physik2.uni-rostock.de/pub/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org

WRKSRC=		${WRKDIR}/faces

USE_X11=	yes

MAKE_ENV+=	MKLINT=no

post-configure:
	@cd ${WRKSRC}; \
	for f in Makefile faces.h x11.c compface/Makefile 		\
		scripts/addxface scripts/facesall scripts/mkfacesindex; do \
		${MV} $$f $$f.in;					\
		${SED} -e 's|@localbase@|'${LOCALBASE}'|g' 		\
			-e 's|@x11prefix@|'${X11PREFIX}'|g'		\
			-e 's|@x11base@|'${X11BASE}'|g' < $$f.in > $$f;	\
	done

# for OBJECT_FMT and OPSYS
.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	${WRKDIR}/.PLIST-src

post-install:
	${LN} -f ${PREFIX}/man/man1/compface.1 ${PREFIX}/man/man1/uncompface.1
	${LN} -f ${PREFIX}/man/man3/compface.3 ${PREFIX}/man/man3/uncompface.3
	@${SED} -e 's|@localbase@|'${LOCALBASE}'|g' \
		-e 's|@x11prefix@|'${X11PREFIX}'|g' < ${PKGDIR}/PLIST > ${PLIST_SRC}
.if (${OBJECT_FMT} == "ELF")
	${LN} -fs ${LOCALBASE}/lib/libcompface.so.1.0 ${LOCALBASE}/lib/libcompface.so.1
	${LN} -fs ${LOCALBASE}/lib/libcompface.so.1.0 ${LOCALBASE}/lib/libcompface.so
.endif

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	SVR4LIBS="-lnsl -lsocket -lgen" SYSV=-DSYSV32 CC=gcc CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
