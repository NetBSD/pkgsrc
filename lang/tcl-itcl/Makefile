# $NetBSD: Makefile,v 1.28 2013/06/06 12:53:47 wiz Exp $
#

DISTNAME=	itcl3.4.1
PKGNAME=	${DISTNAME:S/itcl/tcl-itcl-/}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=incrtcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://incrtcl.sourceforge.net/
COMMENT=	O-O system for Tcl
LICENSE=	2-clause-bsd # ?

GNU_CONFIGURE=	yes

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
