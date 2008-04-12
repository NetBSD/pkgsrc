# $NetBSD: Makefile,v 1.13 2008/04/12 22:43:09 jlam Exp $
#

DISTNAME=		chkrootkit-0.47
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.pangeia.com.br/pub/seg/pac/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.chkrootkit.org/
COMMENT=		Locally checks for signs of a rootkit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake
NO_CONFIGURE=		yes
NOT_FOR_PLATFORM=	NetBSD-[2-9]*-*

PROGRAMS=	chkdirs chklastlog chkproc chkwtmp ifpromisc strings-static \
		chkutmp
DOCDIR=		${PREFIX}/share/doc/chkrootkit

SUBST_CLASSES+=		helper
SUBST_STAGE.helper=	post-patch
SUBST_FILES.helper=	chkrootkit
SUBST_SED.helper=	-e "s|./chklastlog|${PREFIX}/bin/chklastlog|g"	\
			-e "s|./chkproc|${PREFIX}/bin/chkproc|g" 	\
			-e "s|./chkwtmp|${PREFIX}/bin/chkwtmp|g"	\
			-e "s|./chkutmp|${PREFIX}/bin/chkutmp|g"	\
			-e "s|./ifpromisc|${PREFIX}/bin/ifpromisc|g"	\
			-e "s|./strings-static|${PREFIX}/bin/strings-static|g" \
			-e "s|./chkdirs|${PREFIX}/bin/chkdirs|g" 	\
			-e "s|/bin/sh|${SH}|g"

.include "../../mk/compiler.mk"

PLIST_VARS+=	wtmpx
.if ${OPSYS} == "SunOS"
PROGRAMS+=	check_wtmpx
PLIST.wtmpx=	yes
CFLAGS+=	-DSOLARIS2
LDFLAGS+=	-lsocket
.  if empty(CC_VERSION:Mgcc-*)
MAKE_ENV+=	STATIC="-B static"
.  else
MAKE_ENV+=	STATIC="-static"
.  endif
.else
MAKE_ENV+=	STATIC="-static"
.endif

INSTALLATION_DIRS+=	bin

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PROGRAMS} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/chkrootkit ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/chkrootkit
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.chklastlog ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.chkwtmp ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
