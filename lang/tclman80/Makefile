# $NetBSD: Makefile,v 1.1 2000/01/06 20:32:49 drochner Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/08/20 10:33:35 jkh Exp
#

DISTNAME=		tcl8.0.5
PKGNAME=		tclman-8.0.5
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.scriptics.com/

CONFLICTS=		tclman-*

WRKSRC=			${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=		yes

# manual pages only
NO_BUILD=		yes
INSTALL_TARGET=		install-man

post-patch:
	cd ${WRKSRC}/../doc; \
		${MV} Object.3 Tcl_Obj.3

.include "../../mk/bsd.pkg.mk"
