# $NetBSD: Makefile,v 1.19 2004/04/28 05:06:28 snj Exp $
#

DISTNAME=		plt.src.x
PKGNAME=		drscheme-202
DIST_SUBDIR=		${PKGNAME:C/-[0-9]*//}/${PKGNAME:C/.*-([0-9]*)/\1/}
CATEGORIES=		lang
MASTER_SITES=		http://download.plt-scheme.org/bundles/202/plt/ \
			http://www.cs.utah.edu/plt/download/202/plt/ \
			ftp://ftp.pasteur.fr/pub/computing/Scheme/plt-scheme/202/plt/ \
			ftp://archive.informatik.uni-tuebingen.de/unix/language/plt/202/plt/ \
			ftp://morpheus.wish.com.mx/pub/plt/202/plt/

MAINTAINER=		groo@NetBSD.org
HOMEPAGE=		http://www.drscheme.org/
COMMENT=		R4RS-compliant and nearly R5RS-compliant scheme tailored for teaching

CONFLICTS+=		mzscheme-[0-9]*:../../lang/mzscheme

WRKSRC=                 ${WRKDIR}/plt/src
USE_BUILDLINK3=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_PERL5=		yes
GNU_CONFIGURE=		yes

post-patch:
	@for patchee in \
		${WRKDIR}/plt/bin/background-help-desk \
		${WRKDIR}/plt/bin/drscheme \
		${WRKDIR}/plt/bin/help-desk \
		${WRKDIR}/plt/bin/mred \
		${WRKDIR}/plt/bin/mzc \
		${WRKDIR}/plt/bin/mzscheme \
		${WRKDIR}/plt/bin/setup-plt \
		${WRKDIR}/plt/bin/tex2page \
		${WRKDIR}/plt/man/man1/mzscheme.1 \
		${WRKDIR}/plt/collects/slibinit/init.ss \
		${WRKSRC}/mzscheme/src/makeexn \
		${WRKDIR}/plt/man/man1/drscheme.1 \
		${WRKDIR}/plt/man/man1/mred.1; do \
			${MV} -f $$patchee ${WRKSRC}/foo ; \
			${SED} -e 's|@PREFIX@|${PREFIX}|' <${WRKSRC}/foo \
				 > $$patchee ; \
	done;
	@${MV} -f ${WRKSRC}/mred/Makefile.in ${WRKSRC}/foo
	@${SED} -e 's|@X11PREFIX@|${X11PREFIX}|' < ${WRKSRC}/foo > ${WRKSRC}/mred/Makefile.in
	@${RM} -f ${WRKSRC}/foo
	@${FIND} ${WRKDIR} -name '*.orig' -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/plt/collects
	${CP} -p -r ${WRKSRC}/../collects/* ${PREFIX}/lib/plt/collects
	${INSTALL_DATA_DIR} ${PREFIX}/lib/plt/teachpack
	${CP} -p -r ${WRKSRC}/../teachpack/* ${PREFIX}/lib/plt/teachpack
	${INSTALL_DATA_DIR} ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/../include/* ${PREFIX}/include
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/../man/man1/*.1 ${PREFIX}/man/man1/
	${INSTALL_SCRIPT_DIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/../bin/* ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/mzscheme/mzdyn.o ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/mzscheme/libmzgc.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/mzscheme/libmzscheme.a ${PREFIX}/lib
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/plt/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mzscheme/mzscheme ${PREFIX}/lib/plt/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mred/mred ${PREFIX}/lib/plt/bin
	${INSTALL_SCRIPT} ${WRKSRC}/../install ${PREFIX}/lib/plt
	@cd ${PREFIX}/lib/plt && ${ECHO} y | ${SH} install

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
