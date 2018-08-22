# $NetBSD: Makefile,v 1.36 2018/08/22 09:45:21 wiz Exp $

DISTNAME=		oo2c_${BITS}-2.0.11
PKGNAME=		oo2c-2.0.11
PKGREVISION=		16
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ooc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ooc.sourceforge.net/
COMMENT=		Optimizing Oberon-2 Compiler

DEPENDS+=		libtool-base-[0-9]*:../../devel/libtool-base
DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run
USE_LIBTOOL=		yes

TEST_TARGET=		test

INSTALLATION_DIRS=	share/doc/html share/emacs/site-lisp

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	pre-install
SUBST_FILES.destdir=	oo2crc-install.xml
SUBST_SED.destdir=	-e 's,>${PREFIX}/lib<,>${DESTDIR}${PREFIX}/lib<,g'
SUBST_SED.destdir+=	-e 's,>${PREFIX}/lib/oo2c<,>${DESTDIR}${PREFIX}/lib/oo2c<,g'
SUBST_SED.destdir+=	-e 's,>${PREFIX}/bin<,>${DESTDIR}${PREFIX}/bin<,g'

SUBST_CLASSES+=		pkg-unwrap
SUBST_STAGE.pkg-unwrap=	post-install
SUBST_FILES.pkg-unwrap=	${DESTDIR}${PREFIX}/lib/oo2c/oo2crc.xml
SUBST_SED.pkg-unwrap=	-e 's,${WRAPPER_DIR},${LOCALBASE},g'

.include "../../mk/bsd.prefs.mk"

BITS=32
.for PLAT in ${LP64PLATFORMS}
.  if !empty(MACHINE_PLATFORM:M${PLAT})
BITS=64
.  endif
.endfor

post-install:
	${LN} -sf ${PREFIX}/lib/oo2c/oocdoc/html ${DESTDIR}${PREFIX}/share/doc/html/oo2c
	${LN} -sf ${PREFIX}/lib/oo2c/emacs ${DESTDIR}${PREFIX}/share/emacs/site-lisp/oo2c

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
