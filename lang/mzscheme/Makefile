# $NetBSD: Makefile,v 1.1.1.1 2000/01/10 22:09:15 pooka Exp $

DISTNAME=		mzscheme.src.unix
PKGNAME=		mzscheme-101
CATEGORIES=		lang
MASTER_SITES=		http://www.cs.rice.edu/CS/PLT/packages/download/101/mzscheme/

MAINTAINER=		pooka@netbsd.org
HOMEPAGE=		http://www.cs.rice.edu/CS/PLT/packages/mzscheme/

USE_GMAKE=		yes

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=			${WRKDIR}/plt/src/mzscheme

post-patch:
	@for patchee in ${WRKDIR}/plt/man/man1/mzscheme.1 \
	${WRKSRC}/cmdline.inc ${WRKDIR}/plt/collects/mzlib/restartr.ss \
	${WRKDIR}/plt/collects/slibinit/init.ss \
	${WRKSRC}/src/makeexn ; do \
		${MV} -f $$patchee ${WRKSRC}/foo ; \
		${SED} -e 's@XXXPREFIXXXX@${PREFIX}@g' <${WRKSRC}/foo \
			> $$patchee ; \
	done
	@${RM} -f ${WRKSRC}/foo

do-build:
	@(cd ${WRKSRC} ; ./mzmake)

post-build:
	@(cd ${WRKSRC} ; ${MAKE} install)
	@(cd ${WRKDIR}/plt ; ${ECHO} y | ./install)

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/plt/bin/mzscheme ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/plt/bin/mzc ${PREFIX}/bin
	@${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/plt/bin
	@${INSTALL_PROGRAM} ${WRKDIR}/plt/.bin/netbsd/mzscheme \
		${PREFIX}/lib/plt/bin
	@${INSTALL_MAN} ${WRKDIR}/plt/man/man1/mzscheme.1 \
		${PREFIX}/man/man1
	@${CP} -R ${WRKDIR}/plt/collects ${PREFIX}/lib/plt

.include "../../mk/bsd.pkg.mk"
