# $NetBSD: Makefile,v 1.14 2008/06/16 13:45:55 joerg Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_TARGET=	install install-doc

post-install:
	chmod -x ${DESTDIR}${PREFIX}/share/dejagnu/runtest.exp

.include "../../mk/bsd.pkg.mk"
