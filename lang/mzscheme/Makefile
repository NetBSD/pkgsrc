# $NetBSD: Makefile,v 1.9 2003/09/18 12:48:35 yyamano Exp $

DISTNAME=		mzscheme.src.unix
PKGNAME=		mzscheme-200
WRKSRC=			${WRKDIR}/plt/src/mzscheme
CATEGORIES=		lang
MASTER_SITES=		http://download.plt-scheme.org/bundles/200/mzscheme/
DIST_SUBDIR=		${PKGNAME_NOREV}
PKGREVISION=		1

MAINTAINER=		pooka@NetBSD.org
HOMEPAGE=		http://www.plt-scheme.org/software/mzscheme/
COMMENT=		R5RS-compliant scheme

CONFLICTS+=		drscheme*:../drscheme

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../configure

ONLY_FOR_PLATFORM=	NetBSD-*-i386
ONLY_FOR_PLATFORM+=	Linux-*-i386

post-patch:
	@for patchee in ${WRKDIR}/plt/man/man1/mzscheme.1 \
	${WRKDIR}/plt/collects/slibinit/init.ss ; do \
		${MV} -f $$patchee ${WRKSRC}/foo ; \
		${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' <${WRKSRC}/foo \
			> $$patchee ; \
	done
	@${RM} -f ${WRKSRC}/foo

do-install:
	@(cd ${WRKDIR}/plt/src/mzscheme/mzscheme ; ${MAKE} normal-install)
	@${INSTALL_DATA_DIR} ${PREFIX}/include/mzscheme
	@${INSTALL_DATA} ${WRKDIR}/plt/include/*.h ${PREFIX}/include/mzscheme
	@${INSTALL_MAN} ${WRKDIR}/plt/man/man1/mzscheme.1 ${PREFIX}/man/man1
	@([ -d ${PREFIX}/lib/plt ] || ${INSTALL_DATA_DIR} ${PREFIX}/lib/plt)
	@${CP} -R ${WRKDIR}/plt/collects ${PREFIX}/lib/plt

.include "../../mk/bsd.pkg.mk"
