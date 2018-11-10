# $NetBSD: Makefile,v 1.1 2018/11/10 19:58:16 wiz Exp $

DISTNAME=	schily-2018-10-30
PKGNAME=	bosh-20181030
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=schilytools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://schilytools.sourceforge.net/bosh.html
COMMENT=	The Schily Bourne Shell
LICENSE=	cddl-1.0

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	tbl
TOOL_DEPENDS+=	smake-[0-9]*:../../devel/smake
SMAKE=		MAKEFLAGS= smake
MAKE_FLAGS+=	DESTDIR=${DESTDIR} INS_BASE=${PREFIX} DEFMANBASE=. MANDIR=${PKGMANDIR}
# Honor CPPFLAGS, CFLAGS and LDFLAGS
MAKE_FLAGS+=	CPPOPTX=${CPPFLAGS:Q} COPTX=${CFLAGS:Q} LDOPTX=${LDFLAGS:Q}

PKG_SHELL=		bin/bosh
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

# Shared platform specific code for schilytools (provided by smake package)
.include "../../devel/smake/Makefile.common"

do-configure:
	cd ${WRKSRC}/inc && ${SMAKE} ${MAKE_FLAGS}

do-build:
	cd ${WRKSRC} && for library in					\
		libschily libxtermcap libfind libgetopt libshedit;	\
	do								\
		cd ${WRKSRC}/$${library} && ${SMAKE} ${MAKE_FLAGS};	\
	done
	cd ${WRKSRC}/sh && ${SMAKE} ${MAKE_FLAGS}

# Process tables in manpage
post-build:
	cd ${WRKSRC} && ${TBL} sh/sh.1 >sh/sh.1.tmp;			\
		${MV} -f sh/sh.1.tmp sh/bosh.1

do-test:
	cd ${WRKSRC}/sh &&						\
		cd tests; ${SMAKE} ${MAKE_FLAGS} tests

do-install:
	cd ${WRKSRC}/sh &&						\
		${INSTALL_PROGRAM} ${WRKSRC}/sh/OBJ/*/sh		\
			${DESTDIR}${PREFIX}/bin/bosh;			\
		${INSTALL_MAN} ${WRKSRC}/sh/bosh.1 			\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;		\

.include "../../mk/bsd.pkg.mk"
