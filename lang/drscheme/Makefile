# $NetBSD: Makefile,v 1.1.1.1 2000/05/22 20:26:59 groo Exp $
#

DISTNAME=		plt.src.x
PKGNAME=		drscheme-101
CATEGORIES=		lang
MASTER_SITES=		http://www.cs.rice.edu/CS/PLT/packages/download/101/plt/

MAINTAINER=		groo@netbsd.org
HOMEPAGE=		http://www.cs.rice.edu/CS/PLT/packages/drscheme/

DEPENDS+=               mzscheme-101:../mzscheme

USE_GMAKE=		yes

ONLY_FOR_PLATFORM=	NetBSD-*-i386

# Note: WRKSRC set to ease import of patches
# from lang/mzscheme. [groo]

WRKSRC=                 ${WRKDIR}/plt/src/mzscheme

post-patch:
	@for patchee in ${WRKDIR}/plt/man/man1/mzscheme.1 \
	${WRKDIR}/plt/man/man1/drscheme.1 ${WRKDIR}/plt/man/man1/mred.1 \
	${WRKDIR}/plt/man/man1/drscheme-jr.1 \
	${WRKSRC}/cmdline.inc ${WRKDIR}/plt/collects/mzlib/restartr.ss \
	${WRKDIR}/plt/collects/slibinit/init.ss \
	${WRKSRC}/src/makeexn ${WRKDIR}/plt/collects/launcher/launcherr.ss; do \
		${MV} -f $$patchee ${WRKSRC}/foo ; \
		${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' <${WRKSRC}/foo \
			> $$patchee ; \
	done
	@${RM} -f ${WRKSRC}/foo

do-build:
	@(cd ${WRKSRC} ; ./mzmake)
	@(cd ${WRKSRC}/../mred ; ${GMAKE})

post-build:
	@(cd ${WRKSRC} ; ${MAKE} install)
	@(cd ${WRKDIR}/plt ; ${ECHO} y | ./install)

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/plt/bin/drscheme ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/plt/bin/drscheme-jr ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/plt/bin/help-desk ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/plt/bin/mred ${PREFIX}/bin
	@${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/plt/bin
	@${INSTALL_PROGRAM} ${WRKDIR}/plt/src/mred/mred \
		${PREFIX}/lib/plt/bin
	@${INSTALL_MAN} ${WRKDIR}/plt/man/man1/drscheme.1 \
		${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKDIR}/plt/man/man1/drscheme-jr.1 \
		${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKDIR}/plt/man/man1/mred.1 \
		${PREFIX}/man/man1
	@for i in userspce stepper mred icons htdp hierlist \
		help graphics games framework drscheme-jr drscheme \
		doc cogen browser afm; do \
		${CP} -R ${WRKDIR}/plt/collects/$$i ${PREFIX}/lib/plt/collects; \
	done
	@${CP} -R ${WRKDIR}/plt/teachpack ${PREFIX}/lib/plt

.include "../../mk/bsd.pkg.mk"
