# $NetBSD: Makefile,v 1.1.1.1 2000/07/25 13:02:07 wulf Exp $
#

DISTNAME=	geneweb-3.06
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/geneweb/Src/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://cristal.inria.fr/~ddr/GeneWeb/

DEPENDS+=	ocaml-3.*:../../lang/ocaml
DEPENDS+=	camlp4-3.*:../../lang/camlp4

USE_GMAKE=	yes

.if !exists(${LOCALBASE}/bin/ocamlc.opt)
ALL_TARGET=	out
.endif

pre-configure:
		if ! ${TEST} -x ${LOCALBASE}/bin/ocamlc.opt; then \
		  ${ECHO} "No optimized ocaml binaries found"; \
		  cd ${WRKSRC}/tools/; \
		  ${MV} Makefile.inc Makefile.inc.orig; \
		  ${SED} -e "s/\.opt//g" Makefile.inc.orig > Makefile.inc; \
		fi

post-build:
		cd ${WRKSRC} && ${GMAKE} distrib
		${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/geneweb.sh \
			>${WRKDIR}/geneweb.sh

do-install:
		${MKDIR} ${PREFIX}/share/examples/geneweb
		${MKDIR} ${PREFIX}/share/doc/geneweb
		${MKDIR} ${PREFIX}/share/geneweb/etc
		${MKDIR} ${PREFIX}/share/geneweb/images
		${MKDIR} ${PREFIX}/share/geneweb/lang
		${MKDIR} ${PREFIX}/share/geneweb/setup
		cd ${WRKSRC}/distribution/gw && \
		${INSTALL_PROGRAM} gwd ${PREFIX}/libexec && \
		${INSTALL_PROGRAM} consang ${PREFIX}/bin && \
		${INSTALL_PROGRAM} gwc ${PREFIX}/bin && \
		${INSTALL_PROGRAM} ged2gwb ${PREFIX}/bin && \
		${INSTALL_PROGRAM} gwb2ged ${PREFIX}/bin && \
		${INSTALL_PROGRAM} gwsetup ${PREFIX}/sbin && \
		${INSTALL_PROGRAM} gwu ${PREFIX}/bin && \
		${CP} -Rp doc/* ${PREFIX}/share/doc/geneweb && \
		${CP} -Rp etc ${PREFIX}/share/geneweb && \
		${CP} -Rp images ${PREFIX}/share/geneweb && \
		${CP} -Rp lang ${PREFIX}/share/geneweb && \
		${CP} -Rp setup ${PREFIX}/share/geneweb && \
		${INSTALL_DATA} a.gwf ${PREFIX}/share/examples/geneweb && \
		${INSTALL_DATA} only.txt ${PREFIX}/share/examples/geneweb
		${INSTALL_SCRIPT} ${WRKDIR}/geneweb.sh ${PREFIX}/etc/rc.d

.include "../../mk/bsd.pkg.mk"
