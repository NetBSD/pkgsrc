# $NetBSD: Makefile,v 1.1.1.1 2001/03/07 04:24:39 kei Exp $
# FreeBSD Id: ports/misc/rpm2cpio/Makefile,v 1.2 1999/08/25 07:22:29 obrien Exp

DISTNAME=	rpm2cpio
PKGNAME=	rpm2cpio-1.0
CATEGORIES=	misc
MASTER_SITES=	http://www.iagora.com/~espel/
EXTRACT_SUFX=	# none

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.iagora.com/~espel/index.html
COMMENT=	Convert .rpm files for extraction with cpio, needs just perl

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} .

USE_PERL5=	# defined

do-build:
	${PERL5} -i.bak -p -e "if (1 .. 1) {s-^#!/usr/bin/perl-#!${PERL5}-;}" ${WRKDIR}/rpm2cpio

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rpm2cpio ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
