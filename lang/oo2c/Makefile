# $NetBSD: Makefile,v 1.2 2003/05/03 20:44:41 jtb Exp $

.if (${MACHINE_ARCH} == "alpha") || (${MACHINE_ARCH} == "sparc64")
DISTNAME=		oo2c_64-2.0.8
.else
DISTNAME=		oo2c_32-2.0.8
.endif
PKGNAME=		oo2c-2.0.8
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ooc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://ooc.sourceforge.net
COMMENT=		Optimizing Oberon-2 Compiler

DEPENDS+=		libtool-base-[0-9]*:../../devel/libtool
DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
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

.include "../../devel/boehm-gc/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
