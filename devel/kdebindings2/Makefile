# $NetBSD: Makefile,v 1.1.1.1 2001/03/14 17:33:12 skrll Exp $
#

DISTNAME=		kdebindings-2.1
CATEGORIES=		devel kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=		Additional language bindings for KDE integrated X11 desktop

DEPENDS+=		gtk+-1.2.8:../../x11/gtk
DEPENDS+=		python-2.0:../../lang/python

.include "../../x11/kde2/Makefile.part2"

CONFIGURE_ENV+=		PYTHONDIR=${LOCALBASE} \
			LIBPYTHON="-lpython2.0 -lutil"

PLIST_SUBST+=		PYTHON_LIBDIR=lib/python2.0
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
