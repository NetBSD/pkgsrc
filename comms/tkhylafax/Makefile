# $NetBSD: Makefile,v 1.35 2021/04/21 08:55:46 wiz Exp $

DISTNAME=	tkhylafax-3.1
PKGREVISION=	4
CATEGORIES=	comms
MASTER_SITES=	# ftp://ftp.sgi.com/sgi/fax/contrib/tkhylafax/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.elgro.demon.co.uk/resources.html
COMMENT=	Tcl/tk interface to Sam Leffler's fax package

DEPENDS+=	gv>=3.5.8nb1:../../print/gv
DEPENDS+=	hylafax>=4.1:../../comms/hylafax
DEPENDS+=	tk>=8.3.2:../../x11/tk

WRKSRC=		${WRKDIR}/tkhylafax
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
