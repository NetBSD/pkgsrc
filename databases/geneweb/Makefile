# $NetBSD: Makefile,v 1.7 2001/12/05 16:03:56 agc Exp $
#

DISTNAME=	geneweb-4.02
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/geneweb/Src/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://cristal.inria.fr/~ddr/GeneWeb/
COMMENT=	GeneWeb is a comprehensive genealogy database application

DEPENDS+=	ocaml-3.01:../../lang/ocaml
DEPENDS+=	camlp4-3.01.6:../../lang/camlp4

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
		${CAT} ${FILESDIR}/geneweb.sh | \
		${SED} -e s#@PREFIX@#${PREFIX}#g > ${WRKDIR}/geneweb.sh

do-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/examples/geneweb
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/geneweb
		${INSTALL_DATA_DIR} ${PREFIX}/share/geneweb/etc
		${INSTALL_DATA_DIR} ${PREFIX}/share/geneweb/gwtp_tmp
		${INSTALL_DATA_DIR} ${PREFIX}/share/geneweb/images
		${INSTALL_DATA_DIR} ${PREFIX}/share/geneweb/lang
		${INSTALL_DATA_DIR} ${PREFIX}/share/geneweb/setup
		cd ${WRKSRC}/distribution/gw && \
		${INSTALL_PROGRAM} gwd ${PREFIX}/libexec && \
		${INSTALL_PROGRAM} consang ${PREFIX}/bin && \
		${INSTALL_PROGRAM} gwc ${PREFIX}/bin && \
		${INSTALL_PROGRAM} gwtp_tmp/gwtp ${PREFIX}/bin && \
		${INSTALL_PROGRAM} ged2gwb ${PREFIX}/bin && \
		${INSTALL_PROGRAM} gwb2ged ${PREFIX}/bin && \
		${INSTALL_PROGRAM} gwsetup ${PREFIX}/sbin && \
		${INSTALL_PROGRAM} gwu ${PREFIX}/bin && \
		${CP} -Rp doc/* ${PREFIX}/share/doc/geneweb && \
		${CP} -Rp etc ${PREFIX}/share/geneweb && \
		${CP} -Rp gwtp_tmp ${PREFIX}/share/geneweb && \
		${CP} -Rp images ${PREFIX}/share/geneweb && \
		${CP} -Rp lang ${PREFIX}/share/geneweb && \
		${CP} -Rp setup ${PREFIX}/share/geneweb && \
		${INSTALL_DATA} a.gwf ${PREFIX}/share/examples/geneweb && \
		${INSTALL_DATA} only.txt ${PREFIX}/share/examples/geneweb
		${INSTALL_SCRIPT} ${WRKDIR}/geneweb.sh ${PREFIX}/etc/rc.d/geneweb
		${TOUCH} ${PREFIX}/share/geneweb/gwtp_tmp/passwd
		${TOUCH} ${PREFIX}/share/geneweb/gwtp_tmp/gwtp.log
		${CHMOD} 600 ${PREFIX}/share/geneweb/gwtp_tmp/passwd
		${CHMOD} 600 ${PREFIX}/share/geneweb/gwtp_tmp/gwtp.log
		${CHOWN} -R nobody.${ROOT_GROUP} ${PREFIX}/share/geneweb

.include "../../mk/bsd.pkg.mk"
