# $NetBSD: Makefile,v 1.1.1.1 1999/12/04 12:56:29 scw Exp $

DISTNAME=		DAPSource
PKGNAME=		dap-2.0.2
WRKSRC=			${WRKDIR}/dap
CATEGORIES=		audio
MASTER_SITES=		http://www.cee.hw.ac.uk/~richardk/

MAINTAINER=		scw@netbsd.org
HOMEPAGE=		http://www.cee.hw.ac.uk/~richardk/

DEPENDS+=		xforms-0.88:../../x11/xforms

MAKEFILE=		Makefile.netbsd
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arm32 *-*-i386 *-*-m68k *-*-sparc *-*-ns32k

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${PREFIX}/bin/dap

.include "../../mk/bsd.pkg.mk"
