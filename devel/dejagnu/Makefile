# $NetBSD: Makefile,v 1.15 2012/10/31 11:16:52 asau Exp $
#

DISTNAME=	dejagnu-1.4.4
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=dejagnu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/dejagnu/dejagnu.html
COMMENT=	TCL/Expect-based framework for regression testing

DEPENDS+=	tcl-expect>=5.32.1:../../lang/tcl-expect

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install install-doc

post-install:
	chmod -x ${DESTDIR}${PREFIX}/share/dejagnu/runtest.exp

.include "../../mk/bsd.pkg.mk"
