# $NetBSD: Makefile,v 1.2 1999/01/05 00:32:28 kim Exp $
#
# There was a reason for the last digit and the patch number in
# the distribution not matching, but it escapes me right now.

DISTNAME=	skill-3.7@P5
PKGNAME=	skill-3.7.6
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://jaguar.cs.utah.edu/pub/skill/
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
