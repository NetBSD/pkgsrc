# $NetBSD: Makefile,v 1.7 2001/11/09 03:03:03 dogcow Exp $
#

DISTNAME=		plt.src.x
PKGNAME=		drscheme-103p1
CATEGORIES=		lang
MASTER_SITES=		http://www.cs.rice.edu/CS/PLT/packages/download/103p1/plt/

MAINTAINER=		groo@netbsd.org
HOMEPAGE=		http://www.cs.rice.edu/CS/PLT/packages/drscheme/
COMMENT=		R4RS-compilant and nearly R5RS-compliant scheme tailored for teaching

CONFLICTS+=		mzscheme-[0-9]*:../mzscheme

USE_GMAKE=		yes
USE_PERL5=		yes
GNU_CONFIGURE=		yes
LDFLAGS=		-L${LOCALBASE}/lib
CFLAGS=			-I${LOCALBASE}/include

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=                 ${WRKDIR}/plt/src
DIST_SUBDIR=		drscheme/103p1

post-patch:
	@for patchee in ${WRKDIR}/plt/man/man1/mzscheme.1 \
	${WRKDIR}/plt/man/man1/drscheme.1 ${WRKDIR}/plt/man/man1/mred.1 \
	${WRKDIR}/plt/man/man1/drscheme-jr.1 \
	${WRKSRC}/mzscheme/cmdline.inc \
	${WRKDIR}/plt/collects/mzlib/restartr.ss \
	${WRKDIR}/plt/collects/slibinit/init.ss \
	${WRKSRC}/mzscheme/src/makeexn \
	${WRKSRC}/../bin/drscheme \
	${WRKSRC}/../bin/drscheme-jr \
	${WRKSRC}/../bin/help-desk \
	${WRKSRC}/../bin/mred \
	${WRKSRC}/../bin/mzc \
	${WRKSRC}/../bin/mzscheme \
	${WRKDIR}/plt/collects/launcher/launcherr.ss; do \
		${MV} -f $$patchee ${WRKSRC}/foo ; \
		${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' <${WRKSRC}/foo \
			> $$patchee ; \
	done
	@${RM} -f ${WRKSRC}/foo

post-build:
	@(cd ${WRKSRC} ; ${MAKE} install)

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/plt/bin/drscheme ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/plt/bin/drscheme-jr ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/plt/bin/help-desk ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/plt/bin/mred ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/plt/bin/mzscheme ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/plt/bin/mzc ${PREFIX}/bin
	@${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/plt/bin
	@${INSTALL_PROGRAM} ${WRKDIR}/plt/src/mred/mred \
		${PREFIX}/lib/plt/bin
	@${INSTALL_PROGRAM} ${WRKDIR}/plt/src/mzscheme/mzscheme \
		${PREFIX}/lib/plt/bin
	@${INSTALL_MAN} ${WRKDIR}/plt/man/man1/drscheme.1 \
		${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKDIR}/plt/man/man1/drscheme-jr.1 \
		${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKDIR}/plt/man/man1/mred.1 \
		${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/lib/plt/collects
	${CP} -R ${WRKDIR}/plt/collects/* ${PREFIX}/lib/plt/collects
	${CP} -R ${WRKDIR}/plt/teachpack ${PREFIX}/lib/plt
	${CP} -R ${WRKDIR}/plt/notes ${PREFIX}/lib/plt

.include "../../mk/bsd.pkg.mk"
