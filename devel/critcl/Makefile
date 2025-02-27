# $NetBSD: Makefile,v 1.2 2025/02/27 02:08:21 scole Exp $

DISTNAME=	critcl-3.3.1
PKGREVISION=	1
CATEGORIES=	devel tcl
MASTER_SITES=	${MASTER_SITE_GITHUB:=andreas-kupries/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.tcl-lang.org/page/Critcl
COMMENT=	Tcl utility to provide on-the-fly compilation and execution of C code
LICENSE=	modified-bsd

USE_TOOLS+=	env find ls

EXAM_DIR=		share/examples/critcl
INSTALLATION_DIRS+=	${PKGMANDIR}/mann ${EXAM_DIR}

DEPENDS+=		tcllib-[0-9]*:../../devel/tcllib

# in .../critcl.tcl, temporary compilation files are created in $HOME.
# override to ${WRKSRC} for pkgsrc build
# xxx use libtool for compilation and plist
do-build:
	cd ${WRKSRC} && ${ENV} HOME=${WRKSRC} \
	${TCLSH} ./build.tcl install --prefix ${DESTDIR}${PREFIX}

# handle shared library/arch dependent file names
GENERATE_PLIST+=	(cd ${DESTDIR}${PREFIX} && ${LS} \
			lib/critcl_callback_tcl8-1.1/*/* \
			lib/critcl_md5c_tcl8-0.12/*/*);

do-install:
	# do nothing

# add man pages and examples
post-install:
	cd ${WRKSRC}/embedded/man/files && \
	 ${INSTALL_MAN} * ${DESTDIR}${PREFIX}/${PKGMANDIR}/mann
	cd ${WRKSRC}/examples; for d in `${FIND} . -type d -print`; do \
	 ${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${EXAM_DIR}/$$d; done
	cd ${WRKSRC}/examples; for f in `${FIND} . -type f -print`; do \
	 ${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/${EXAM_DIR}/$$f; done

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
