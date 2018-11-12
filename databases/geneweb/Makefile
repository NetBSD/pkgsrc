# $NetBSD: Makefile,v 1.53 2018/11/12 16:10:17 jaapb Exp $
#

DISTNAME=	geneweb-5.01
PKGREVISION=	17
CATEGORIES=	databases
EXTRACT_SUFX=	.tgz
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/geneweb/Src/
MASTER_SITES+=	http://www.sartorelli.gen.nz/GeneWeb/Src/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.geneweb.org/
COMMENT=	GeneWeb is a genealogy database that runs as a web server

# A macports packages is at:
#  http://db.macports.org/port/show/903

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pax
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
INSTALL_PROGRAM= ${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

INSTALLATION_DIRS=	bin libexec sbin share/examples/geneweb \
			share/doc/geneweb share/geneweb/etc \
			share/geneweb/gwtp_tmp share/geneweb/images \
			share/geneweb/lang share/geneweb/setup

post-build:
		cd ${WRKSRC} && ${GMAKE} distrib

# XXX maybe:
#   gwc2 update_nldb
# XXX doc should be in html
# XXX LICENSE.txt should be installed

do-install:
	${CHMOD} -R go+rX ${WRKSRC}/distribution/gw
	${CHMOD} 444 ${WRKSRC}/distribution/gw/etc/*
	cd ${WRKSRC}/distribution/gw && \
	${INSTALL_PROGRAM} gwd ${DESTDIR}${PREFIX}/libexec && \
	${INSTALL_PROGRAM} consang ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_PROGRAM} gwc ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_PROGRAM} gwtp_tmp/gwtp ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_PROGRAM} ged2gwb ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_PROGRAM} gwb2ged ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_PROGRAM} gwsetup ${DESTDIR}${PREFIX}/sbin && \
	${INSTALL_PROGRAM} gwu ${DESTDIR}${PREFIX}/bin && \
	(cd doc && pax -rw -pp * ${DESTDIR}${PREFIX}/share/doc/geneweb) && \
	pax -rw -pp etc ${DESTDIR}${PREFIX}/share/geneweb && \
	pax -rw -pp gwtp_tmp ${DESTDIR}${PREFIX}/share/geneweb && \
	pax -rw -pp images ${DESTDIR}${PREFIX}/share/geneweb && \
	pax -rw -pp lang ${DESTDIR}${PREFIX}/share/geneweb && \
	pax -rw -pp setup ${DESTDIR}${PREFIX}/share/geneweb && \
	${INSTALL_DATA} a.gwf ${DESTDIR}${PREFIX}/share/examples/geneweb && \
	${INSTALL_DATA} only.txt ${DESTDIR}${PREFIX}/share/examples/geneweb
	${TOUCH} ${DESTDIR}${PREFIX}/share/geneweb/gwtp_tmp/passwd
	${TOUCH} ${DESTDIR}${PREFIX}/share/geneweb/gwtp_tmp/gwtp.log
	${CHMOD} 600 ${DESTDIR}${PREFIX}/share/geneweb/gwtp_tmp/passwd
	${CHMOD} 600 ${DESTDIR}${PREFIX}/share/geneweb/gwtp_tmp/gwtp.log

.include "../../lang/camlp5/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
