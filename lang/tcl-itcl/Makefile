# $NetBSD: Makefile,v 1.29 2014/01/11 14:42:01 adam Exp $
#

DISTNAME=	itcl3.4.1
PKGNAME=	${DISTNAME:S/itcl/tcl-itcl-/}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=incrtcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://incrtcl.sourceforge.net/
COMMENT=	O-O system for Tcl
LICENSE=	2-clause-bsd # ?

GNU_CONFIGURE=	yes

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
