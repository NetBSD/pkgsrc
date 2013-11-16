# $NetBSD: Makefile,v 1.1.1.1 2013/11/16 21:01:26 asau Exp $
#

DISTNAME=	TclOO1.0.1
PKGNAME=	${DISTNAME:S/TclOO/tcl-tclOO-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Core for other TCL OO extensions and basic TCL OO framework
LICENSE=	2-clause-bsd # with custom, non-effective terms, same as Tcl

# Note: TclOO is included in Tcl8.6, delete this package after pkgsrc bumps Tcl
CONFLICTS=	tcl-9* tcl-8.[6-9].*

GNU_CONFIGURE=	yes

# Make sure package installs all necessary headers:
INSTALL_TARGET=	install install-private-headers

SUBST_CLASSES+=			manpages
SUBST_STAGE.manpages=	post-patch
SUBST_MESSAGE.manpages=	Fixing manual pages
SUBST_FILES.manpages=	doc/*.[3n]
SUBST_SED.manpages=		-e "/^\\.so /d"

post-build:
	${MV} ${WRKSRC}/doc/class.n ${WRKSRC}/doc/tclOO-class.n

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
