# $NetBSD: Makefile,v 1.3 1999/01/05 19:12:00 kim Exp $
#
# The version number for skill does not match the @P number.
# This is normal.

DISTNAME=	skill-3.7@P6
PKGNAME=	skill-3.7.7
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://fast.cs.utah.edu/pub/skill/
EXTRACT_SUFX=	_tar.Z

MAINTAINER=	kim@tac.nyc.ny.us

BINMODE=	02555
BINGRP=		kmem

MAKE_ENV+=	UVM=${UVM}

pre-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skill ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/skill.1 ${PREFIX}/man/man1
	ln -s skill ${PREFIX}/bin/snice
	ln -s skill.1 ${PREFIX}/man/man1/snice.1

.include "../../mk/bsd.pkg.mk"
