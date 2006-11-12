# $NetBSD: Makefile,v 1.21 2006/11/12 01:43:21 rillig Exp $

DISTNAME=		oo2c_${BITS}-2.0.11
PKGNAME=		oo2c-2.0.11
PKGREVISION=		7
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ooc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ooc.sourceforge.net/
COMMENT=		Optimizing Oberon-2 Compiler

DEPENDS+=		libtool-base-[0-9]*:../../devel/libtool-base
DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt

.if ${MACHINE_ARCH} == alpha || ${MACHINE_ARCH} == sparc64 \
	|| ${MACHINE_ARCH} == x86_64
BITS=64
.else
BITS=32
.endif

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run
USE_LIBTOOL=		yes

EVAL_PREFIX+=		LIBTOOL_PREFIX=libtool-base
LIBTOOL_PREFIX_DEFAULT=	${LOCALBASE}

pre-install:
	for f in ${WRKSRC}/rsrc/OOC/oo2crc.xml; do			\
		${SED} -e 's,${BUILDLINK_DIR},${LIBTOOL_PREFIX},g'	\
		$$f > $$f.tmp && ${MV} $$f.tmp $$f;			\
	done

post-install:
	cd ${PREFIX}/share/doc/html && ${LN} -sf ${PREFIX}/lib/oo2c/oocdoc/html oo2c
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	cd ${PREFIX}/share/emacs/site-lisp && ${LN} -sf ${PREFIX}/lib/oo2c/emacs oo2c

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
