# $NetBSD: Makefile,v 1.13 2005/05/16 03:04:45 jlam Exp $

DISTNAME=		mzscheme-205.src.unix
PKGNAME=		mzscheme-205
CATEGORIES=		lang
MASTER_SITES=		http://download.plt-scheme.org/bundles/205/mzscheme/

MAINTAINER=		pooka@NetBSD.org
HOMEPAGE=		http://www.plt-scheme.org/software/mzscheme/
COMMENT=		R5RS-compliant scheme

CONFLICTS+=		drscheme*:../drscheme

WRKSRC=			${WRKDIR}/plt/src
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./configure
EXTRACT_USING=		pax

ONLY_FOR_PLATFORM=	NetBSD-*-i386
ONLY_FOR_PLATFORM+=	Linux-*-i386

post-patch:
	@for patchee in ${WRKDIR}/plt/man/man1/mzscheme.1 \
			${WRKDIR}/plt/man/man1/help-desk.1 \
			${WRKDIR}/plt/collects/make/setup-extension.ss \
			${WRKDIR}/plt/collects/slibinit/init.ss ; do \
		${MV} -f $$patchee ${WRKSRC}/foo ; \
		${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' <${WRKSRC}/foo \
			> $$patchee ; \
	done
	@${RM} -f ${WRKSRC}/foo

do-install:
	@(cd ${WRKDIR}/plt/src/mzscheme ; ${MAKE} normal-install)
	@${INSTALL_DATA_DIR} ${PREFIX}/include/mzscheme
	@${INSTALL_DATA} ${WRKDIR}/plt/include/*.h ${PREFIX}/include/mzscheme
	@${INSTALL_MAN} ${WRKDIR}/plt/man/man1/mzscheme.1 ${PREFIX}/man/man1
	@([ -d ${PREFIX}/lib/plt ] || ${INSTALL_DATA_DIR} ${PREFIX}/lib/plt)
	@${CP} -R ${WRKDIR}/plt/collects ${PREFIX}/lib/plt

.include "../../mk/bsd.pkg.mk"
