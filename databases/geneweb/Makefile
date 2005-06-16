# $NetBSD: Makefile,v 1.25 2005/06/16 06:57:44 jlam Exp $
#

DISTNAME=	geneweb-4.10
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/geneweb/Src/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://cristal.inria.fr/~ddr/GeneWeb/
COMMENT=	GeneWeb is a comprehensive genealogy database application

DIST_SUBDIR=	${PKGNAME}
USE_PKGINSTALL=	yes
USE_TOOLS+=	gmake

RCD_SCRIPTS=	geneweb

.if !exists(${LOCALBASE}/bin/ocamlc.opt)
BUILD_TARGET=	out
.endif

.include "../../mk/bsd.prefs.mk"

# sysutils/coreutils a 'gwc' program, so conflict with it if
# ${GNU_PROGRAM_PREFIX} == "g"
.if ${GNU_PROGRAM_PREFIX} == "g"
CONFLICTS+=	coreutils-[0-9]*
.endif

# Stripped OCAML binaries don't seem to work nolonger
# Installing unstripped binaries until this is fixed
INSTALL_PROGRAM =  ${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

INSTALLATION_DIRS=	bin libexec sbin

pre-configure:
		if ! ${TEST} -x ${LOCALBASE}/bin/ocamlc.opt; then \
		  ${ECHO} "No optimized ocaml binaries found"; \
		  cd ${WRKSRC}/tools/; \
		  ${MV} Makefile.inc Makefile.inc.orig; \
		  ${SED} -e "s/\.opt//g" Makefile.inc.orig > Makefile.inc; \
		fi

post-build:
		cd ${WRKSRC} && ${GMAKE} distrib

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
		${TOUCH} ${PREFIX}/share/geneweb/gwtp_tmp/passwd
		${TOUCH} ${PREFIX}/share/geneweb/gwtp_tmp/gwtp.log
		${CHMOD} 600 ${PREFIX}/share/geneweb/gwtp_tmp/passwd
		${CHMOD} 600 ${PREFIX}/share/geneweb/gwtp_tmp/gwtp.log
		${CHOWN} -R nobody.${ROOT_GROUP} ${PREFIX}/share/geneweb

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
