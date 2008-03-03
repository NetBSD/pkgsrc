# $NetBSD: Makefile,v 1.31 2008/03/03 15:21:07 jlam Exp $
#

DISTNAME=	geneweb-4.10
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/geneweb/Src/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://cristal.inria.fr/~ddr/GeneWeb/
COMMENT=	GeneWeb is a comprehensive genealogy database application

DIST_SUBDIR=	${PKGNAME_NOREV}nb1

PKG_DESTDIR_SUPPORT=	destdir

USE_TOOLS+=	gmake

RCD_SCRIPTS=	geneweb

.if !exists(${LOCALBASE}/bin/ocamlc.opt)
BUILD_TARGET=	out
.endif

.include "../../mk/bsd.prefs.mk"

# needed for patch-ab to work:
# since 3.09.0, camlp4 uses _loc instead of loc
BUILDLINK_API_DEPENDS.ocaml+=       ocaml>=3.09.0

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
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/geneweb
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/geneweb
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/geneweb/etc
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/geneweb/gwtp_tmp
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/geneweb/images
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/geneweb/lang
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/geneweb/setup
		cd ${WRKSRC}/distribution/gw && \
		${INSTALL_PROGRAM} gwd ${DESTDIR}${PREFIX}/libexec && \
		${INSTALL_PROGRAM} consang ${DESTDIR}${PREFIX}/bin && \
		${INSTALL_PROGRAM} gwc ${DESTDIR}${PREFIX}/bin && \
		${INSTALL_PROGRAM} gwtp_tmp/gwtp ${DESTDIR}${PREFIX}/bin && \
		${INSTALL_PROGRAM} ged2gwb ${DESTDIR}${PREFIX}/bin && \
		${INSTALL_PROGRAM} gwb2ged ${DESTDIR}${PREFIX}/bin && \
		${INSTALL_PROGRAM} gwsetup ${DESTDIR}${PREFIX}/sbin && \
		${INSTALL_PROGRAM} gwu ${DESTDIR}${PREFIX}/bin && \
		${CP} -Rp doc/* ${DESTDIR}${PREFIX}/share/doc/geneweb && \
		${CP} -Rp etc ${DESTDIR}${PREFIX}/share/geneweb && \
		${CP} -Rp gwtp_tmp ${DESTDIR}${PREFIX}/share/geneweb && \
		${CP} -Rp images ${DESTDIR}${PREFIX}/share/geneweb && \
		${CP} -Rp lang ${DESTDIR}${PREFIX}/share/geneweb && \
		${CP} -Rp setup ${DESTDIR}${PREFIX}/share/geneweb && \
		${INSTALL_DATA} a.gwf ${DESTDIR}${PREFIX}/share/examples/geneweb && \
		${INSTALL_DATA} only.txt ${DESTDIR}${PREFIX}/share/examples/geneweb
		${TOUCH} ${DESTDIR}${PREFIX}/share/geneweb/gwtp_tmp/passwd
		${TOUCH} ${DESTDIR}${PREFIX}/share/geneweb/gwtp_tmp/gwtp.log
		${CHMOD} 600 ${DESTDIR}${PREFIX}/share/geneweb/gwtp_tmp/passwd
		${CHMOD} 600 ${DESTDIR}${PREFIX}/share/geneweb/gwtp_tmp/gwtp.log
		${CHOWN} -R nobody.${ROOT_GROUP} ${DESTDIR}${PREFIX}/share/geneweb

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
