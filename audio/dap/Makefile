# $NetBSD: Makefile,v 1.3 2000/02/22 14:26:50 scw Exp $

DISTNAME=		dap-2.1
CATEGORIES=		audio
MASTER_SITES=		http://www.cee.hw.ac.uk/~richardk/
EXTRACT_SUFX=		.tgz

MAINTAINER=		scw@netbsd.org
HOMEPAGE=		http://www.cee.hw.ac.uk/~richardk/

DEPENDS+=		xpm-*:../../graphics/xpm
DEPENDS+=		xforms-0.88:../../x11/xforms

MAKEFILE=		Makefile.netbsd
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arm32 *-*-i386 *-*-m68k *-*-sparc *-*-ns32k

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${PREFIX}/bin/dap

.include "../../mk/bsd.pkg.mk"
