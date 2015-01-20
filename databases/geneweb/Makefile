# $NetBSD: Makefile,v 1.40 2015/01/20 14:24:35 jaapb Exp $
#

DISTNAME=	geneweb-5.01
PKGREVISION=	6
CATEGORIES=	databases
EXTRACT_SUFX=	.tgz
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/geneweb/Src/ \
		http://www.sartorelli.gen.nz/GeneWeb/Src/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.geneweb.org/
COMMENT=	GeneWeb is a genealogy database that runs as a web server

# A macports packages is at:
#  http://db.macports.org/port/show/903

PKG_DESTDIR_SUPPORT=	destdir

USE_TOOLS+=	gmake
HAS_CONFIGURE=	YES

# ocaml can compile in two modes; if the optimizing compiler
# is not present (limited support across architectures), ask
# the geneweb build system to build non-optimized versions.
.if !exists(${LOCALBASE}/bin/ocamlc.opt)
BUILD_TARGET=	out
.endif

RCD_SCRIPTS=	geneweb

.include "../../mk/bsd.prefs.mk"

# sysutils/coreutils installs a 'gwc' program, so conflict with it
CONFLICTS+=	coreutils-[0-9]*

# Stripped OCAML binaries don't seem to work any more.
# Installing unstripped binaries until this is fixed.
# (not checked in 5.01)
INSTALL_PROGRAM =  ${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

# XXX How does this relate to do-install?
INSTALLATION_DIRS=	bin libexec sbin

post-build:
		cd ${WRKSRC} && ${GMAKE} distrib

# XXX do not use CP
# XXX better permission fix
# XXX maybe:
#   gwc2 update_nldb
# XXX doc should be in html
# XXX LICENSE.txt should be installed

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
		${CHMOD} 444 etc/* && \
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
		${CHOWN} -R root:${ROOT_GROUP} ${DESTDIR}${PREFIX}/share/geneweb

.include "../../lang/camlp5/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
