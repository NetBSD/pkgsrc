# $NetBSD: Makefile,v 1.21 2004/10/03 00:15:00 tv Exp $
#

DISTNAME=		plt-${DRSCHEME_VERSION}-src-unix
PKGNAME=		drscheme-${DRSCHEME_VERSION}
PKGREVISION=	1
DIST_SUBDIR=		${PKGNAME:C/-[0-9]*//}/${PKGNAME:C/.*-([0-9]*)/\1/}
CATEGORIES=		lang
MASTER_SITES=		http://download.plt-scheme.org/bundles/${DRSCHEME_VERSION}/plt/ \
			http://www.cs.utah.edu/plt/download/${DRSCHEME_VERSION}/plt/ \
			ftp://ftp.pasteur.fr/pub/computing/Scheme/plt-scheme/${DRSCHEME_VERSION}/plt/ \
			ftp://archive.informatik.uni-tuebingen.de/unix/language/plt/${DRSCHEME_VERSION}/plt/ \
			ftp://morpheus.wish.com.mx/pub/plt/${DRSCHEME_VERSION}/plt/
EXTRACT_SUFX=		.tgz

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

DRSCHEME_VERSION=	207

# XXX: we pass this as the prefix to the configure script (see below) so
#      the mzc compiler finds all the right includes and libs
PLT_HOME=		${PREFIX}/lib/plt

PROGRAMS=	drscheme framework-test framework-test-engine games help-desk \
		mred mzc mzpp mzscheme mztext pdf-slatex setup-plt slatex     \
		slideshow tex2page web-server web-server-monitor web-server-text

post-patch:
	@for patchee in 						\
		${WRKDIR}/plt/bin/mred 					\
		${WRKDIR}/plt/bin/mzscheme 				\
		${WRKDIR}/plt/man/man1/mzscheme.1 			\
		${WRKDIR}/plt/collects/slibinit/init.ss 		\
		${WRKDIR}/plt/collects/dynext/compile-unit.ss		\
		${WRKSRC}/mzscheme/src/makeexn 				\
		${WRKDIR}/plt/man/man1/drscheme.1 			\
		${WRKDIR}/plt/man/man1/mred.1; do 			\
			${MV} -f $$patchee ${WRKSRC}/foo ; 		\
			${SED} -e 's|@PREFIX@|${LOCALBASE}|' <${WRKSRC}/foo \
				 > $$patchee ; 				\
	done;
	@${MV} -f ${WRKSRC}/mred/Makefile.in ${WRKSRC}/foo
	@${SED} -e 's|@X11PREFIX@|${X11PREFIX}|' < ${WRKSRC}/foo > ${WRKSRC}/mred/Makefile.in
	@${RM} -f ${WRKSRC}/foo
	@${FIND} ${WRKDIR} -name '*.orig' -print | ${XARGS} ${RM} -f

post-install:
	${INSTALL_MAN_DIR} ${LOCALBASE}/man/man1
	${INSTALL_MAN} ${WRKSRC}/../man/man1/*.1 ${PREFIX}/man/man1/
	@cd ${PREFIX}/lib/plt && PATH="${OLD_PATH}" ${SH} install || ${TRUE}
.for f in ${PROGRAMS}
	@cd ${PREFIX}/bin && ${LN} -s ../lib/plt/bin/$f
.endfor

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# See comment above.
CONFIGURE_ARGS+=	--prefix=${PLT_HOME}

# XXX: Gack.  Ugly hackery to have the install process run with the regular
#      PATH.
.for _dir_ in ${PATH:C/:/ /g}
.  if empty(PREPEND_PATH:M${_dir_})
OLD_PATH:=	${_dir_}:${OLD_PATH}
.  endif
.endfor
