# $NetBSD: Makefile,v 1.6 2001/10/15 22:46:17 skrll Exp $
#

DISTNAME=		kdebindings-2.2.1
CATEGORIES=		devel kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=		Additional language bindings for KDE integrated X11 desktop

DEPENDS+=		kdebase-2.2.1:../../x11/kdebase2
DEPENDS+=		gtk+>=1.2.9:../../x11/gtk
DEPENDS+=		python21>=2.1:../../lang/python21

.include "../../x11/kde2/Makefile.part2"

CONFIGURE_ENV+=		PYTHONDIR=${LOCALBASE} \
			LIBPYTHON="-lpython2.1 -lutil"

PLIST_SUBST+=		PYTHON_LIBDIR=lib/python2.1
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
