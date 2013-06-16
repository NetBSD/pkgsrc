# $NetBSD: Makefile,v 1.20 2013/06/16 10:11:58 shattered Exp $
#

DISTNAME=		chkrootkit-0.49
#KGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.pangeia.com.br/pub/seg/pac/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.chkrootkit.org/
COMMENT=		Locally checks for signs of a rootkit
LICENSE=		modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake
NO_CONFIGURE=		yes

PROGRAMS=	chkdirs chklastlog chkproc chkwtmp ifpromisc strings-static \
		chkutmp
DOCDIR=		${PREFIX}/share/doc/chkrootkit

SUBST_CLASSES+=		helper
SUBST_STAGE.helper=	post-patch
SUBST_FILES.helper=	chkrootkit
SUBST_SED.helper=	-e "s|./chklastlog|${PREFIX}/bin/chklastlog|g"
SUBST_SED.helper+=	-e "s|./chkproc|${PREFIX}/bin/chkproc|g"
SUBST_SED.helper+=	-e "s|./chkwtmp|${PREFIX}/bin/chkwtmp|g"
SUBST_SED.helper+=	-e "s|./chkutmp|${PREFIX}/bin/chkutmp|g"
SUBST_SED.helper+=	-e "s|./ifpromisc|${PREFIX}/bin/ifpromisc|g"
SUBST_SED.helper+=	-e "s|./strings-static|${PREFIX}/bin/strings-static|g"
SUBST_SED.helper+=	-e "s|./chkdirs|${PREFIX}/bin/chkdirs|g"
SUBST_SED.helper+=	-e "s|/bin/sh|${SH}|g"

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

INSTALLATION_DIRS+=	bin ${DOCDIR}

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PROGRAMS} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/chkrootkit ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.chklastlog ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.chkwtmp ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
